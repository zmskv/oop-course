#include <iostream>
#include "./src/rhombus.cpp"
#include "./src/hexagon.cpp"
#include "./src/pentagon.cpp"

void printMenu()
{
    std::cout << "1. Add a figure" << std::endl;
    std::cout << "2. Remove a figure" << std::endl;
    std::cout << "3. Calculate the total area of all figures" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

Figure *addFigure()
{
    std::cout << "Choose the type of figure:" << std::endl;
    std::cout << "1. Hexagon" << std::endl;
    std::cout << "2. Pentagon" << std::endl;
    std::cout << "3. Rhombus" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        Point points[6];
        std::cout << "Enter the coordinates of six points (x y):" << std::endl;
        for (int i = 0; i < 6; ++i)
        {
            std::cin >> points[i];
        }
        return new Hexagon(points);
    }
    case 2:
    {
        Point points[5];
        std::cout << "Enter the coordinates of five points (x y):" << std::endl;
        for (int i = 0; i < 5; ++i)
        {
            std::cin >> points[i];
        }
        return new Pentagon(points);
    }
    case 3:
    {
        Point points[4];
        std::cout << "Enter the coordinates of four points (x y):" << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            std::cin >> points[i];
        }
        return new Rhombus(points);
    }
    default:
        std::cout << "Invalid choice." << std::endl;
        return nullptr;
    }
}

int main()
{
    int maxFigures;
    std::cout << "Enter the number of elements to create the array for: ";
    std::cin >> maxFigures;

    Figure *figures[maxFigures];
    int figureCount = 0;

    while (true)
    {
        printMenu();
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (figureCount >= maxFigures)
            {
                std::cout << "Array is full. Cannot add more figures." << std::endl;
            }
            else
            {
                Figure *figure = addFigure();
                if (figure)
                {
                    figures[figureCount++] = figure;
                }
            }
            break;
        }
        case 2:
        {
            if (figureCount == 0)
            {
                std::cout << "No figures to remove." << std::endl;
            }
            else
            {
                std::cout << "Enter the index of the figure to remove (from 0 to " << figureCount - 1 << "): ";
                int index;
                std::cin >> index;
                if (index >= 0 && index < figureCount)
                {
                    delete figures[index]; 
                    for (int i = index; i < figureCount - 1; ++i)
                    {
                        figures[i] = figures[i + 1];
                    }
                    --figureCount;
                    std::cout << "Figure removed." << std::endl;
                }
                else
                {
                    std::cout << "Invalid index." << std::endl;
                }
            }
            break;
        }
        case 3:
        {
            double totalArea = 0.0;
            for (int i = 0; i < figureCount; ++i)
            {
                totalArea += static_cast<double>(*figures[i]);
            }
            std::cout << "Total area of all figures: " << totalArea << std::endl;
            break;
        }
        case 4:
            std::cout << "Exiting the program." << std::endl;
            for (int i = 0; i < figureCount; ++i)
            {
                delete figures[i];
            }
            return 0;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}