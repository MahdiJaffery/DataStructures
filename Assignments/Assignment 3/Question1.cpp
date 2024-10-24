#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace sf;

struct Person
{
    Texture texture;
    Sprite sprite;
    int data;
};

class Node
{
public:
    Person person;
    Node *next;
    Node(int value) : next(nullptr)
    {
        person.data = value;
        if (!person.texture.loadFromFile("genBajwa.jpg"))
        {
            cout << "Failed to load the image!" << endl;
        }
        person.sprite.setTexture(person.texture);
    }
};

class Queue
{
    int size;
    Node *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    bool isEmpty()
    {
        return !front;
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue()
    {
        int data = front->person.data;
        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        return data;
    }

    int getSize()
    {
        return size;
    }

    Node *getFront()
    {
        if (isEmpty())
        {
            cerr << "Queue is empty. There is no front element." << endl;
            return nullptr;
        }
        return front;
    }

    int getFrontVal()
    {
        return front->person.data;
    }
};

void ask(int &n, int &k)
{
    RenderWindow window(VideoMode(1000, 600), "Josephus Problem");
    Color pastelColor(96, 128, 210);
    window.clear(pastelColor);
    window.setFramerateLimit(60);
    Font font;
    font.loadFromFile("COOPBL.ttf");

    Text instruction1("Enter the total number of people (N):", font, 30);
    instruction1.setFillColor(Color::Black);
    instruction1.setPosition(20, 20);

    Text instruction2("Enter the counting interval (K):", font, 30);
    instruction2.setFillColor(Color::Black);
    instruction2.setPosition(20, 120);

    RectangleShape inputFieldN(Vector2f(200, 40));
    inputFieldN.setFillColor(Color::White);
    inputFieldN.setOutlineThickness(2);
    inputFieldN.setOutlineColor(Color::Black);
    inputFieldN.setPosition(20, 70);

    RectangleShape inputFieldK(Vector2f(200, 40));
    inputFieldK.setFillColor(Color::White);
    inputFieldK.setOutlineThickness(2);
    inputFieldK.setOutlineColor(Color::Black);
    inputFieldK.setPosition(20, 170);

    Text inputTextN("", font, 30);
    inputTextN.setFillColor(Color::Black);
    inputTextN.setPosition(25, 75);

    Text inputTextK("", font, 30);
    inputTextK.setFillColor(Color::Black);
    inputTextK.setPosition(25, 175);

    string inputN;
    string inputK;

    bool isInputtingN = false;
    bool isInputtingK = false;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                Vector2i mousePos = Mouse::getPosition(window);

                if (inputFieldN.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    isInputtingN = true;
                    isInputtingK = false;
                }
                else if (inputFieldK.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    isInputtingK = true;
                    isInputtingN = false;
                }
                else
                {
                    isInputtingN = false;
                    isInputtingK = false;
                }
            }
            else if (event.type == Event::TextEntered)
            {
                if (isInputtingN && event.text.unicode < 128)
                {
                    if (event.text.unicode == '\b' && !inputN.empty())
                    {
                        inputN.pop_back();
                    }
                    else if (isdigit(static_cast<char>(event.text.unicode)))
                    {
                        inputN += static_cast<char>(event.text.unicode);
                    }
                    inputTextN.setString(inputN);
                }
                else if (isInputtingK && event.text.unicode < 128)
                {
                    if (event.text.unicode == '\b' && !inputK.empty())
                    {
                        inputK.pop_back();
                    }
                    else if (isdigit(static_cast<char>(event.text.unicode)))
                    {
                        inputK += static_cast<char>(event.text.unicode);
                    }
                    inputTextK.setString(inputK);
                }
            }
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Return)
            {
                if (!inputN.empty() && !inputK.empty())
                {
                    n = stoi(inputN);
                    k = stoi(inputK);
                    window.close();
                }
            }
        }

        window.clear(pastelColor);
        window.draw(instruction1);
        window.draw(instruction2);
        window.draw(inputFieldN);
        window.draw(inputFieldK);
        window.draw(inputTextN);
        window.draw(inputTextK);
        window.display();
    }
}

void display(RenderWindow &window, Queue &queue)
{
    Color pastelColor(96, 128, 210);
    int radius = 250;
    int centerX = window.getSize().x / 2;
    int centerY = window.getSize().y / 2;
    int totalElements = queue.getSize();

    if (totalElements == 0)
    {
        return;
    }

    float angleStep = 360.0f / totalElements;
    float currentAngle = 0.0f;
    window.clear(pastelColor);

    Node *currentPerson = queue.getFront(); // Get the front of the queue

    // Define the scale factor for the image
    float scale = 0.1f;

    int deletionCount = 0; // Count the number of deletions

    for (int i = 0; i < totalElements; i++)
    {
        float x = centerX + radius * cos(currentAngle * 3.14f / 180.0f);
        float y = centerY + radius * sin(currentAngle * 3.14f / 180.0f);

        // Set the position of the person's sprite
        currentPerson->person.sprite.setPosition(x, y);

        // Set the scale of the image
        currentPerson->person.sprite.setScale(scale, scale);

        // Create a text for the number
        Font font;
        font.loadFromFile("COOPBL.ttf");
        Text numberText(to_string(currentPerson->person.data), font, 20); //	Serial Number of the soldiers
        numberText.setFillColor(Color::Black);
        numberText.setPosition(x - 10, y - 10);

        window.draw(currentPerson->person.sprite);
        window.draw(numberText);

        currentAngle += angleStep;
        currentPerson = currentPerson->next; // Move to the next person in the queue
    }

    window.display();
}

void winner(int w, int s, int *exec, int n)
{
    RenderWindow window(VideoMode(1000, 600), "Josephus Problem");
    Color pastelColor(96, 128, 210);
    window.clear(pastelColor);
    window.setFramerateLimit(60);
    Font font;
    font.loadFromFile("COOPBL.ttf");
    s = s + 1;
    Text startText("Starting Element (S): " + to_string(s), font, 30);
    startText.setFillColor(Color::Black);
    startText.setPosition(20, 20);

    Text winnerText("Survivor is General Bajwa no. : " + to_string(w), font, 30);
    winnerText.setFillColor(Color::Black);
    winnerText.setPosition(20, 100);

    Text execText("Order of Execution:", font, 30);
    execText.setFillColor(Color::Black);
    execText.setPosition(20, 180);

    Text execOrderText("", font, 30);
    execOrderText.setFillColor(Color::Black);
    execOrderText.setPosition(20, 300);

    for (int i = 0; i < n; i++)
    {
        execOrderText.setString(execOrderText.getString() + to_string(exec[i]) + " ");
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear(pastelColor);

        window.draw(startText);
        window.draw(winnerText);
        window.draw(execText);
        window.draw(execOrderText);

        window.display();
    }
}

int main()
{
    int N, K;

    RenderWindow window(VideoMode(1000, 600), "Josephus Problem");
    Color pastelColor(207, 196, 171);
    window.clear(pastelColor);
    window.setFramerateLimit(60);
    Font font;
    font.loadFromFile("COOPBL.ttf");

    ask(N, K);

    int S = 1;
    srand((time(0)));
    S = rand() % N + 1;

    cout << "Randomly selected starting point S: " << S << endl;

    if (N < 1 || K < 1)
    {
        cout << "Invalid input. N and K must be greater than 0." << endl;
        return 1;
    }

    Queue people;
    for (int i = 1; i <= N; i++)
    {
        people.enqueue(i);
    }

    int *exec = new int[N];

    for (int i = 0; i < S; i++)
    {
        people.enqueue(people.dequeue());
    }

    int w = 0, f = 0;
    cout << "Execution order: ";
    while (!people.isEmpty())
    {
        display(window, people);
        Event event;
        while (window.waitEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Space)
                {
                    break;
                }
            }
            if (event.type == Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        for (int i = 0; i < K - 1; i++)
        {
            people.enqueue(people.dequeue());
        }
        w = people.dequeue();
        cout << w << " ";
        exec[f] = w;
        f++;
    }
    cout << endl;
    cout << "Survivor is General Bajwa No. : " << w;

    winner(w, S - 1, exec, N);
    delete[] exec;
    exec = nullptr;
}