#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include "Graph.h"

using namespace std;
//Constructor
Graph::Graph(int size){
	cout << "Graph object being created with max nodes size:" << size << "\n\n";
	graphSize = size;
	// cout << "Graph object created"<<endl;
}

void Graph::addNode(int node){
	nodeArray.push_back(node);
	cout << "adding node" << endl;
}

void Graph::addEdge(int node1, int node2){
	edge1Array.push_back(node1);
	edge2Array.push_back(node2);
	cout << "adding edge" << node1 << node2 <<"\n";
}
void Graph::addUEdge(int node1, int node2){
	addEdge(node1,node2);
	addEdge(node2,node1);
}

int Graph::checkNode(int node){
	/*
	Checks the node 
	Returns 1 if the node is found 0 otherwise
	*/

	for(int i=0; i< nodeArray.size(); i++){
		if (nodeArray[i] == node){
			cout << "The node exists\n";
			return 1;
		}
	}
	return 0;
}
int Graph::checkEdge(int node1, int node2){
	/*
	Checks the edge (node1,node2)
	Returns 1 if the edge is found 0 otherwise
	*/
	for(int i=0; i< edge1Array.size(); i++){
		if (edge1Array[i] == node1 && edge2Array[i] == node2){
			return 1;
		}
	}
	return 0;
}

void Graph::deleteNode(int node){
	/*
	Deletes the node from the nodeArray
	*/
	int out;
	out = checkNode(node);
	if (out ==1 ){
		int count = 0;
		//find the node and delete it
		//Using an iterator to go through the vector
		for (vector<int>::const_iterator i = nodeArray.begin(); i != (nodeArray.end());i++){
			if (*i == node){
				nodeArray.erase(nodeArray.begin() + count);
			}
			count++; 
		}

	}
	else{
	}
}

void Graph::printNodeList(void){
	/*
	Prints the node list
	*/
	for (vector<int>::const_iterator i = nodeArray.begin(); i != (nodeArray.end());i++){
		cout << "Node :" << (*i) <<endl;
	}
}

void Graph::deleteUEdge(int node1, int node2){
	/*
	Delete the edge (node1, node2)
	(node2, node1)
	*/
	deleteEdge(node1,node2);
	deleteEdge(node2,node1);
}

void Graph::deleteEdge(int node1, int node2){
	/*
	Deletes the edge (node1, node2)
	If the edge does not exist, then nothing is done.
	*/

	int out;
	out = checkEdge(node1, node2);
	if (out ==1 ){ //The edge exists
		int count = 0;
		//find the node and delete it
		//Using an iterator to go through the vector
		for (vector<int>::const_iterator i = edge1Array.begin(); i != (edge1Array.end());i++){
			if (*((edge1Array.begin() + count)) == node1 && *((edge1Array.begin() + count)) == node2){
				edge1Array.erase(edge1Array.begin() + count);
				edge2Array.erase(edge2Array.begin() + count);
			}
			count++; 
		}

	}
	else{ //The edge does not exist. Dont do anything.
	}
}

int Graph::connectedComponents(void ){
	/*
	Computes the connected compoonents of the UNDIRECTED graph
	stores the components in an map :(node, component_number)  
	private data: connected_components

	Suggestion: Maybe this is the update function!
	And we need another function that can access the connected components and give it
	to you
	*/


	//Create an adjacency list
	map< int, vector<int> > adjacency_list;
	int count = 0;
	//Go through the edge list and create the adjacency list
	for (vector<int>::const_iterator i = edge1Array.begin(); i != (edge1Array.end());i++){
		adjacency_list[edge1Array[count]].push_back(edge2Array[count]);
		count++;
	}
	// print the connected components
	for (map< int , vector<int> >::iterator it = adjacency_list.begin();it != adjacency_list.end();it++){
		vector<int> value_list = it->second;
		for (int i =0;i<value_list.size();i++){
		}
	}

	// Create a map from node to components
	map<int,int> component_number;
	count = 0;
	for (int k=0;k<nodeArray.size();k++){
		if (component_number.find(count) == component_number.end()){
			//if not assigned a component_number - start a BFS
			int node = nodeArray[k];
			int original_node = node;
			vector<int> first_nodes = adjacency_list[node];
			for (int i=0; i<first_nodes.size();i++){
			}
			while(!first_nodes.empty()){
				int curr_node = first_nodes.back();
				first_nodes.pop_back();
				if (component_number.find(curr_node) == component_number.end()){
					//If current node is not assigned a component number
					component_number[curr_node] = original_node;
					vector<int> curr_node_list = adjacency_list[curr_node];
					for (int l = 0; l<curr_node_list.size() ; l++){
					}
					int node_list_len = curr_node_list.size();
					for (int j = 0;j<node_list_len;j++){
						first_nodes.push_back(curr_node_list.back());
						curr_node_list.pop_back();
					}

				}

			}

		}else{
			//The node is assigned a component number

		}
		count++;
	}
	cout << "\n\nConnected Components\n";
	for (int l=0;l<nodeArray.size();l++){   
		int node = nodeArray[l];
		cout << "node is:" << node << "  connected_component:" << component_number[node] << endl;

	}
	return 1;
}
