#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <class T>
class Stack
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
    };

    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            Node *current = top;
            top = top->next;
            delete current;
        }
    }

    bool IsEmpty()
    {
        return (!top);
    }

    bool push(const T &val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
        return true;
    }

    bool pop(T &val)
    {
        if (IsEmpty())
        {
            return false;
        }
        else
        {
            val = top->data;
            Node *current = top;
            top = top->next;
            delete current;
            return true;
        }
    }

    bool peek(T &val)
    {
        if (IsEmpty())
        {
            return false;
        }
        else
        {
            val = top->data;
            return true;
        }
    }
};

class XMLData
{
public:
    int lineNumber;
    bool StartOrEnd;
    string tagText;
    bool hasAttribute;
    bool attributes;

    XMLData()
    {
        lineNumber = 0;
        StartOrEnd = 0;
        tagText = "";
        hasAttribute = false;
        attributes = true;
    }

    void Checking(string filename)
    {
        Stack<XMLData> St;
        ifstream file;
        file.open(filename);
        string inputLine;
        int lineNum = 1;
        bool Error = false;

        while (getline(file, inputLine))
        {
            size_t pos = 0;
            while (pos < inputLine.length())
            {

                if (inputLine[pos] == '<')
                {
                    pos++;
                    XMLData xml;
                    xml.lineNumber = lineNum;
                    if (inputLine[pos] == '/')
                    {
                        xml.StartOrEnd = 1;
                        pos++;
                    }
                    else
                    {
                        xml.StartOrEnd = 0;
                    }

                    if (lineNum == 1 && xml.StartOrEnd == 0 && inputLine.substr(pos, 4) == "?xml")
                    {
                        while (pos < inputLine.length() && inputLine[pos] != '>')
                        {
                            pos++;
                        }
                        if (inputLine[pos] != '>')
                        {
                            cout << "Error: Missing character at inputLine " << lineNum << endl;
                            Error = true;
                            break;
                        }
                        continue;
                    }

                    while (pos < inputLine.length() && inputLine[pos] != '>' && inputLine[pos] != ' ' && inputLine[pos] != '/' && inputLine[pos] != '"' && inputLine[pos] != '\'')
                    {
                        xml.tagText += inputLine[pos];
                        pos++;
                    }

                    if (pos < inputLine.length() && (inputLine[pos] == '"' || inputLine[pos] == '\''))
                    {
                        char ch = inputLine[pos];
                        pos++;
                        while (pos < inputLine.length() && inputLine[pos] != ch)
                        {
                            pos++;
                        }
                        if (inputLine[pos] != ch)
                        {
                            cout << "Error: Unmatched " << ch << " at inputLine " << lineNum << endl;
                            attributes = false;
                            Error = true;
                            break;
                        }
                        pos++;
                    }

                    if (!xml.StartOrEnd)
                    {
                        St.push(xml);
                    }
                    else
                    {
                        XMLData topTag;
                        if (St.peek(topTag))
                        {
                            if (topTag.tagText == xml.tagText)
                            {
                                St.pop(topTag);
                            }
                            else
                            {
                                cout << "Error: Mismatched tag '" << xml.tagText << "' on inputLine " << lineNum << endl;
                                Error = true;
                                break;
                            }
                        }
                        else
                        {
                            cout << "Error: Unexpected ending tag '" << xml.tagText << "' on inputLine " << lineNum << endl;
                            Error = true;
                            break;
                        }
                    }
                }
                pos++;
            }
            lineNum++;

            if (Error)
            {
                break;
            }
        }

        XMLData remainingTag;
        while (St.pop(remainingTag))
        {
            cout << "Error: Unclosed tag '" << remainingTag.tagText << "' at inputLine " << remainingTag.lineNumber << endl;
            Error = true;
        }

        if (!attributes)
        {
            cout << "Error: Unmatched attributes in the file." << endl;
        }

        if (!Error)
        {
            cout << "No syntax errors found in the file." << endl;
        }
    }
};

int main()
{
    XMLData xml;
    xml.Checking("XML.txt");
    return 0;
}