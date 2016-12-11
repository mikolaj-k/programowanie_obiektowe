#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int   data;
	Node* next;
};

Node* arrayToList(const int arr[], size_t size)
{
	Node* head = nullptr;

	for (int i = 0; i < size; i++)
	{
		head = new Node{ arr[size - 1 - i], head };
	}

	return head;
}

Node* removeOdd(Node* head)
{
	Node *pocz = head;
	Node *poprz = nullptr;

	if (head == nullptr)
	{
		cout << "Empty list";
		return nullptr;
	}
	else
	{
		while (head != nullptr)
		{
			if (((head->data % 2) != 0) && (poprz != nullptr))
			{
				poprz->next = head->next;
				head->next = nullptr;

				cout << "deleting : " << head->data << endl;
				delete head;

				head = poprz->next;
			}

			else if (((head->data % 2) != 0) && (poprz == nullptr))
			{
				pocz = head->next;
				head->next = nullptr;
				cout << "deleting : " << head->data << endl;
				delete head;

				head = pocz;
			}
			else
			{
				poprz = head;
				head = head->next;
			}
		}

		return pocz;
	}
}

void showList(const Node* head)
{
	if (head == nullptr)
	{
		cout << "EMPTY LIST" << endl;
	}
	else
	{
		while (head != nullptr)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
}

void deleteList(Node*& head)
{
	Node* poprz = nullptr;

	while (head != nullptr)
	{
		cout << "DEL: " << head->data << " ";
		poprz = head;
		head = head->next;
		delete poprz;
	}
	cout << endl;

	head = nullptr;
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8, 9, 10, 11, 12, 13, 14, 15, 17, 19};
	size_t size = sizeof(arr) / sizeof(*arr);
	Node* head = arrayToList(arr, size);
	showList(head);
	head = removeOdd(head);
	showList(head);
	deleteList(head);
	showList(head);

	system("pause");
}
