#include <string>

class Link {
  private:
    std::string material;

  public:
    Link(std::string material) {
      this->material = material;
    }

    std::string get_material() {
      return this->material;
    }
};

class Node {
  private:
    Link *data;
    Node *next_node;


  public:
    //for tail and head if only one obj
    Node(Link *data) {
      this->data = data;
      this->next_node = nullptr;
    }

    //for internal nodes and head if more than one obj
    Node(Link *data, Node *next_node) {
      this->data = data;
      this->next_node = next_node;
    }

    Node *next() {
      return this->next_node;
    }

    Link *get_data() {
      return this->data;
    }
};
