#pragma once

#include <librdkafka/rdkafkacpp.h>
#include <iostream>
#include <memory>
#include <string>
#include "observer.h"

class BattleStream : public Observer
{
private:
    std::string brokers;
    std::string topic_name;
    std::unique_ptr<RdKafka::Topic> topic;
    std::unique_ptr<RdKafka::Conf> conf;
    std::unique_ptr<RdKafka::Producer> producer;

public:
    BattleStream(const std::string &brokers, const std::string &topic_name);
    virtual ~BattleStream();

    void update(const std::string &event) override;
};
