#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 + g2;
    CHECK(g3.toString() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");

    g1 += g2;
    CHECK(g1.toString() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph subtraction") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 - g2;
    CHECK(g3.toString() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");

    g1 -= g2;
    CHECK(g1.toString() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test graph multiplication") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 * g2;
    CHECK(g3.toString() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");
}

TEST_CASE("Test scalar multiplication and division") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2 = g1 * 3;
    CHECK(g2.toString() == "[0, 3, 0]\n[3, 0, 3]\n[0, 3, 0]");

    g1 *= 2;
    CHECK(g1.toString() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");

    ariel::Graph g3 = g2 / 3;
    CHECK(g3.toString() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");

    g2 /= 3;
    CHECK(g2.toString() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test unary operators") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2 = +g1;
    CHECK(g2.toString() == g1.toString());

    ariel::Graph g3 = -g1;
    CHECK(g3.toString() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]");
}

TEST_CASE("Test increment and decrement operators") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ++g1;
    CHECK(g1.toString() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");

    g1++;
    CHECK(g1.toString() == "[2, 3, 2]\n[3, 2, 3]\n[2, 3, 2]");

    --g1;
    CHECK(g1.toString() == "[1, 2, 1]\n[2, 1, 2]\n[1, 2, 1]");

    g1--;
    CHECK(g1.toString() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]");
}

TEST_CASE("Test comparison operators") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
    CHECK(g1 == g1);

    ariel::Graph g3;
    g3.loadGraph(graph1);

    CHECK(g1 == g3);
    CHECK(g1 <= g3);
    CHECK(g1 >= g3);
    CHECK(g2 > g1);
    CHECK(g1 < g2);
}

TEST_CASE("Test invalid operations") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {0, 1, 1, 1}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g3.loadGraph(graph3);

    CHECK_THROWS(g1 + g2);
    CHECK_THROWS(g1 - g2);
    CHECK_THROWS(g1 * g2);
    CHECK_THROWS(g1 + g3);
    CHECK_THROWS(g1 - g3);
    CHECK_THROWS(g1 * g3);
    CHECK_THROWS(g1 / 0);
}

TEST_CASE("Edge cases") {
    ariel::Graph g1;
    vector<vector<int>> emptyGraph = {};
    CHECK_THROWS(g1.loadGraph(emptyGraph));

    ariel::Graph g2;
    vector<vector<int>> nonSquareGraph = {
        {0, 1},
        {1, 0},
        {0, 1}};
    CHECK_THROWS(g2.loadGraph(nonSquareGraph));

    ariel::Graph g3;
    vector<vector<int>> oneElementGraph = {
        {42}};
    g3.loadGraph(oneElementGraph);
    CHECK(g3.toString() == "[42]");
}
