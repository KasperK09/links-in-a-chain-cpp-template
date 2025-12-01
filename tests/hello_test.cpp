#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/link.hpp"

TEST_CASE("checks if gold and silver get added correctly and be able to get the name") {
    Link gold("Gold");
    REQUIRE(gold.get_material() == "Gold");

    Link silver("Silver");
    REQUIRE(silver.get_material() == "Silver");
}

TEST_CASE("checks if node correctly stores a pointer to link obj") {
    Link gold("Gold");
    Node node(&gold);

    REQUIRE(node.get_data()->get_material() == "Gold");
}

TEST_CASE("checks if nodes link together correclty") {
    Link gold("Gold");
    Link silver("Silver");

    Node node1(&gold);
    Node node2(&silver, &node1);

    REQUIRE(node2.next() == &node1);
    REQUIRE(node2.next()->get_data()->get_material() == "Gold");
}

TEST_CASE("checks if you can go through the list correctly and added elements are inside the correct locations") {
    Link gold("Gold");
    Node node_one(&gold);

    Link silver("Silver");
    Node node_two(&silver, &node_one);

    Link bronze("Bronze");
    Node node_three(&bronze, &node_two);

    Node* current = &node_three;

    REQUIRE(current->get_data()->get_material() == "Bronze");
    current = current->next();

    REQUIRE(current->get_data()->get_material() == "Silver");
    current = current->next();

    REQUIRE(current->get_data()->get_material() == "Gold");
    current = current->next();

    REQUIRE(current == nullptr);
}