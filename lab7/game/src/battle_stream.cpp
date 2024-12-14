#include "../include/battle_stream.h"
#include <stdexcept>

BattleStream::BattleStream(const std::string &brokers, const std::string &topic_name)
    : brokers(brokers), topic_name(topic_name)
{
    std::string errstr;

    conf.reset(RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL));
    if (!conf)
    {
        throw std::runtime_error("Failed to create Kafka configuration");
    }

    if (conf->set("bootstrap.servers", brokers, errstr) != RdKafka::Conf::CONF_OK)
    {
        throw std::runtime_error("Failed to set Kafka brokers: " + errstr);
    }

    producer.reset(RdKafka::Producer::create(conf.get(), errstr));
    if (!producer)
    {
        throw std::runtime_error("Failed to create Kafka producer: " + errstr);
    }

    auto topic_conf = std::unique_ptr<RdKafka::Conf>(RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC));
    if (!topic_conf)
    {
        throw std::runtime_error("Failed to create topic configuration");
    }

    topic.reset(RdKafka::Topic::create(producer.get(), topic_name, topic_conf.get(), errstr));
    if (!topic)
    {
        throw std::runtime_error("Failed to create topic: " + errstr);
    }
}

BattleStream::~BattleStream()
{
    if (producer)
    {
        producer->flush(1000);
    }
}

void BattleStream::update(const std::string &event)
{
    std::cout << "Sending event to Kafka: " << event << std::endl;

    RdKafka::ErrorCode err = producer->produce(
        topic.get(),
        RdKafka::Topic::PARTITION_UA,
        RdKafka::Producer::RK_MSG_COPY,
        const_cast<char *>(event.c_str()),
        event.size(),
        nullptr,
        nullptr);

    if (err != RdKafka::ERR_NO_ERROR)
    {
        std::cerr << "Failed to send message to Kafka: "
                  << RdKafka::err2str(err) << std::endl;
    }
    else
    {
        std::cout << "Message successfully sent to Kafka topic: " << topic_name << std::endl;
    }

    producer->poll(0);
}
