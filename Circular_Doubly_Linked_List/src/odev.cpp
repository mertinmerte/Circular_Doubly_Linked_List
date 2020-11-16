#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include "Obeb.hpp"
#include "Mod.hpp"
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

char GetASCII(int value)
{
	return char(value);
}

void Insert(int value, struct Node** node, int mod, int nodesCount, Node** currentNode)
{
	struct Node* newNode = new Node;
	newNode->data = value;
	if (nodesCount == 1)
	{
		newNode->next = newNode->prev = newNode;
		*node = newNode;
	}
	else
	{
		int counter = 0;
		struct Node *temp = *currentNode;
		if (mod == 0)
		{
			struct Node *next = temp->next;
			temp->next = newNode;
			newNode->prev = temp;
			newNode->next = next;
			next->prev = newNode;
		}
		else
		{
			if (mod >= nodesCount)
			{
				struct Node *last = (*node)->prev;
				newNode->next = *node;
				newNode->data = value;
				newNode->prev = last;
				last->next = (*node)->prev = newNode;
				*node = newNode;
			}
			else
			{
				while (counter != mod) {
					counter++;
					temp = temp->prev;
				}

				struct Node *next = temp->next;
				temp->next = newNode;
				newNode->prev = temp;
				newNode->next = next;
				next->prev = newNode;
			}
		}
	}
}

void Process(int value, int nodesCount, int &mod, int &currentValue, int &obeb, int &maxObeb, Node* node, Node* &currentNode)
{
	Obeb *Ebob = new Obeb();
	Mod *Mode = new Mod();
	if (nodesCount == 1)
	{
		obeb = maxObeb = 0;
		currentValue = value;
	}
	else
	{
		struct Node *first = *(&node);
		currentValue = first->data;
		obeb = Ebob->GetObeb(value, currentValue);
		int counter = 1;
		while (obeb < maxObeb)
		{
			if (counter == nodesCount - 1)
			{
				obeb = maxObeb;
				break;
			}
			else
			{
				node = node->next;
			}
			counter++;
			currentValue = node->data;
			obeb = Ebob->GetObeb(value, currentValue);
		}
		maxObeb = obeb;
		mod = Mode->GetMod(value, currentValue);
		currentNode = node;
	}
}

int main()
{
	string line;
	ifstream inFile;
	size_t pos = 0;
	string separator = " ";
	struct Node* node = NULL;
	struct Node* currentNode = NULL;

	inFile.open("C:\\Users\\Acer\\Desktop\\Circular_Doubly_Linked_List\\doc\\Sayilar.txt");
	while (getline(inFile, line))
	{
		int maxObeb = 0;
		int mod = 0;
		int nodesCount = 0;
		int obeb = 0;
		int currentValue = 0;
		while ((pos = line.find(separator)) != std::string::npos) 
		{
			nodesCount++;
			string token = line.substr(0, pos);
			line.erase(0, pos + separator.length());
			int value = std::stoi(token);
			Process(value, nodesCount, mod, currentValue, obeb, maxObeb, node, currentNode);
			Insert(value, &node, mod, nodesCount, &currentNode);
		}
		nodesCount++;
		Process(std::stoi(line), nodesCount, mod, currentValue, obeb, maxObeb, node, currentNode);
		Insert(std::stoi(line), &node, mod, nodesCount, &currentNode);
		int count = 0;
		cout << "Sifre: ";
		while (count != nodesCount) {
			count++;
			int a = node->data;
			node = node->next;
			cout << GetASCII(a);
		}
		std::endl(std::cout);
		delete(node);
	}
	inFile.close();
	return 0;
}





