#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include "Graph.h"

using namespace std;


int main(){
	int count;
	Graph firstGraph(10);

	firstGraph.addNode(1);

	firstGraph.addNode(2);
	firstGraph.addNode(3);
	firstGraph.addNode(4);
	firstGraph.addNode(5);
	firstGraph.addNode(6);
	firstGraph.addNode(7);
	firstGraph.addNode(8);
	firstGraph.addNode(9);
	firstGraph.addNode(10);
	firstGraph.addNode(11);

	// firstGraph.addUEdge(1,2);
	firstGraph.addUEdge(1,3);
	firstGraph.addUEdge(2,4);
	firstGraph.addUEdge(2,5);
	firstGraph.addUEdge(6,7);
	firstGraph.addUEdge(7,8);
	// firstGraph.addUEdge(8,9);
	firstGraph.addUEdge(9,10);
	firstGraph.addUEdge(10,11);


	// firstGraph.addUEdge(3,4);

	// firstGraph.deleteEdge(1,3);
	firstGraph.deleteUEdge(1,100);
	firstGraph.checkNode(1);

	firstGraph.checkNode(2);
	firstGraph.checkEdge(1,2);
	firstGraph.checkEdge(1,3);
	firstGraph.checkEdge(2,4);

	// firstGraph.deleteNode(1);
	firstGraph.checkNode(1);
	firstGraph.printNodeList();
	firstGraph.deleteNode(100);
	cout << "\n\n\nDONE!!!"<<endl;

	count = firstGraph.connectedComponents();
    return 0;
}