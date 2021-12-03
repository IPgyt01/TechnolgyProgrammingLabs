#pragma once
#include <iostream>

template <class T>
struct Node2 {
	T* val;
	Node2* next;
	Node2* prev;

	Node2(T* _val)
	{
		val = _val;
		prev = nullptr;
		next = nullptr;
	}

	Node2()
	{
		val = nullptr;
		next = nullptr;
		prev = nullptr;
	}
};

template <class T>
class ListTest2 {
public:
	Node2<T>* head;
	int size;

	ListTest2() {
		this->head = new Node2<T>();
		this->head->next = head;
		this->head->prev = head;
		this->size = 0;
	}

	bool is_empty() {
		return size == 0;
	}

	int get_count() {
		return size;
	}

	T* get_addres_Node(int t) {
		if (is_empty()) return nullptr;
		if (t<0 || t> size) return nullptr;
		Node2<T>* p = head->next;
		int k = 0;

		while (p != head) {
			if (k == t)
			{
				return p->val;
			}
			p = p->next;
			k++;
		}
		return nullptr;
	}


	void add_node(T* _val, int number) {

		Node2<T>* p = new Node2<T>(_val);

		if (is_empty())
		{
			this->head->next = p;
			this->head->prev = p;
			p->next = head;
			p->prev = head;
			this->size++;
			return;
		}

		Node2<T>* c = head->next;
		int k = 0;

		while (c != head) {

			if (number == 0)
			{
				head->next = p;
				p->prev = head;
				p->next = c;
				c->prev = p;
				size++;
				return;
			}

			if (number == k + 1 && number < size)
			{
				p->next = c->next;
				c->next->prev = p;
				p->prev = c;
				c->next = p;
				size++;
				return;
			}

			if (k + 1 == number && number == size) {
				c->next = p;
				head->prev = p;
				p->next = head;
				p->prev = c;
				size++;
				return;
			}
			c = c->next;
			k++;
		}
	}


	void delete_node(int number) {

		if (is_empty() || number < 0 || number> size)
		{
			return;
		}

		Node2<T>* c = head->next;
		Node2<T>* del = nullptr;
		int k = 0;



		while (c != head) {
			if (number == k && number == 0 && size == 1)
			{
				del = c;
				head->next = nullptr;
				head->prev = nullptr;
				head->next = head;
				head->prev = head;
				size--;
				break;
			}
			if (number == k && number == 0 && size != 1)
			{
				del = c;
				head->next = c->next;
				c->next->prev = head;
				size--;
				break;
			}
			if (number == k + 1 && number < size - 1)
			{
				del = c->next;
				c->next->next->prev = c;
				c->next = c->next->next;
				size--;
				break;
			}
			if (number == size - 1 && k + 1 == number) {
				del = c->next;
				c->next = head;
				head->prev = c;
				size--;
				break;
			}
			c = c->next;
			k++;
		}
		delete del;
	}
};

