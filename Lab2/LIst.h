#pragma once
#include "ScientificBook.h";
#include <iostream>


struct Node {
	ScientificBook* val;
	Node* next;
	Node(ScientificBook* _val)
	{
		this->val = new ScientificBook();
		this->val->setAuthor(_val->getAuthor());
		this->val->setTitle(_val->getTitle());
		this->val->setPrice(_val->getPrice());
		this->val->setYear(_val->getYear());
		this->val->setCitationRating(_val->getCitationRating());
		this->next = nullptr;
	}
	Node()
	{
		val = nullptr;
		next = nullptr;
	}
};


class ListTest {
public:
	Node* head;
	int size;
	ListTest() {
		this->head = new Node();
		this->head->next = head;
		this->size = 0;
	}
	bool is_empty() {
		return size == 0;
	}
	int get_count() {
		return size;
	}
	Node* get_addres_Node(int t) {
		if (is_empty()) return nullptr;
		if (t<0 || t> size) return nullptr;
		Node* p = head->next;
		int k = 0;
		while (p != head) {
			if (k == t)
			{
				return p;
			}
			p = p->next;
			k++;
		}
		return nullptr;
	}
	void add_node(ScientificBook* _val, int number) {
		Node* p = new Node(_val);
		if (is_empty())
		{
			head->next = p;
			p->next = head;
			size++;
			return;
		}
		Node* c = head->next;
		int k = 0;
		while (c != head) {
			if (number == 0)
			{
				head->next = p;
				p->next = c;
				size++;
				return;
			}
			if (number == k + 1 && number < size)
			{
				p->next = c->next;
				c->next = p;
				size++;
				return;
			}
			if (k + 1 == number && number == size) {
				c->next = p;
				p->next = head;
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
		Node* c = head->next;
		Node* del = nullptr;
		int k = 0;
		while (c != head) {
			if (number == k && number == 0 && size == 1)
			{
				del = c;
				head->next = nullptr;
				size--;
				break;
			}
			if (number == k && number == 0 && size != 1)
			{
				del = c;
				head->next = c->next;
				size--;
				break;
			}
			if (number == k + 1 && number < size - 1)
			{
				del = c->next;
				c->next = c->next->next;
				size--;
				break;
			}
			if (number == size - 1 && k + 1 == number) {
				del = c->next;
				c->next = head;
				size--;
				break;
			}
			c = c->next;
			k++;
		}
		delete del;
	}
};
