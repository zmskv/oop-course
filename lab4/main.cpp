#include <iostream>
#include "./src/rhombus.cpp"
#include "./src/hexagon.cpp"
#include "./src/pentagon.cpp"
#include "./src/array.cpp"

int main()
{
    Array<Figure<double>> figures;

    while (true)
    {
        std::cout << "1. Add Hexagon\n"
                  << "2. Add Pentagon\n"
                  << "3. Add Rhombus\n"
                  << "4. Remove Figure by Index\n"
                  << "5. Print All Figures\n"
                  << "6. Calculate Total Area\n"
                  << "7. Exit\n"
                  << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            Hexagon<double> hexagon;
            std::cin >> hexagon;
            figures.push_back(std::make_shared<Hexagon<double>>(hexagon));
        }
        else if (choice == 2)
        {
            Pentagon<double> pentagon;
            std::cin >> pentagon;
            figures.push_back(std::make_shared<Pentagon<double>>(pentagon));
        }
        else if (choice == 3)
        {
            Rhombus<double> rhombus;
            std::cin >> rhombus;
            figures.push_back(std::make_shared<Rhombus<double>>(rhombus));
        }
        else if (choice == 4)
        {
            size_t index;
            std::cout << "Enter index to remove: ";
            std::cin >> index;
            figures.remove(index);
        }
        else if (choice == 5)
        {
            for (size_t i = 0; i < figures.getSize(); ++i)
            {
                figures[i]->getInfo();
            }
        }
        else if (choice == 6)
        {
            double totalArea = 0;
            for (size_t i = 0; i < figures.getSize(); ++i)
            {
                totalArea += static_cast<double>(*figures[i]);
            }
            std::cout << "Total Area: " << totalArea << std::endl;
        }
        else if (choice == 7)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}