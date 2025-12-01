#include <iostream>

#include "src/link.hpp"

using namespace std;

int main() {
  Link gold("Gold");
  Node node_one(&gold);

  Link silver("Silver");
  Node node_two(&silver, &node_one);

  Link bronze("Bronze");
  Node node_three(&bronze, &node_two);

  Node* retrieved_node_two = node_one.next();
  Node* retrieved_node_three = node_two.next();

 //print linked list
  Node *current = &node_three;

  while (current != nullptr) {
      cout << current->get_data()->get_material();
      cout << " -> ";
      current = current->next();
  }
  cout << "null" << endl;
}
