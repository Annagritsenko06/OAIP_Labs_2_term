#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;

struct Node {
	Node* next;
	int el;
};

int getInt();
void view(Node* start);
void add_el_to_queue(Node*& start, Node*& end, int el);
int del(Node*& start, Node*& end);
int queue_length(Node* start, Node* end);
void find_zero(Node*& start, Node*& end);
int max_queue(Node* start);


