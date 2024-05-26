//322516840
//reutgerber@gmail.com
//task2
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <sstream>

using namespace std;
TEST_CASE("Test 1: graph addition") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 + g2;

    std::vector<std::vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}
    };

    CHECK(g3.getMatrix() == expectedGraph);
}

TEST_CASE("Test 2: graph addition with scalar") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    int scalar = 3;
    g1 += scalar;

    std::vector<std::vector<int>> expectedGraph = {
        {3, 4, 3},
        {4, 3, 4},
        {3, 4, 3}
    };

    CHECK(g1.getMatrix() == expectedGraph);
}

TEST_CASE("Test 3: graph unary plus operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    +g1;  

    CHECK(g1.getMatrix() == graph);   
}

TEST_CASE("Test 4: graph subtraction") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {2, 3, 2},
        {3, 2, 3},
        {2, 3, 2}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g2 - g1;

    std::vector<std::vector<int>> expectedGraph = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };

    CHECK(g3.getMatrix() == expectedGraph);
}

TEST_CASE("Test 5: graph subtraction with scalar") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {2, 3, 2},
        {3, 2, 3},
        {2, 3, 2}
    };
    g1.loadGraph(graph);

    int scalar = 2;
    g1 -= scalar;

    std::vector<std::vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    CHECK(g1.getMatrix() == expectedGraph);
}

TEST_CASE("Test 6: graph unary minus operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {1, -2, 3},
        {-4, 5, -6},
        {7, -8, 9}
    };
    g1.loadGraph(graph);

    -g1;

    std::vector<std::vector<int>> expectedGraph = {
        {-1, 2, -3},
        {4, -5, 6},
        {-7, 8, -9}
    };

    CHECK(g1.getMatrix() == expectedGraph);
}
TEST_CASE("Test 7: graph output operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph);
    std::stringstream ss;
    ss << g1;

    std::string expectedOutput =
        "[1, 2, 3]\n"
        "[4, 5, 6]\n"
        "[7, 8, 9]\n\n";

    CHECK(ss.str() == expectedOutput);
}
TEST_CASE("Test 8: graph equality operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3;
    std::vector<std::vector<int>> graph3 = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };
    g3.loadGraph(graph3);

    CHECK(g1 == g2);  // הגרפים צריכים להיות שווים
    CHECK(!(g1 == g3));  // הגרפים לא צריכים להיות שווים
}

TEST_CASE("Test 9: graph comparison operators") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3;
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };
    g3.loadGraph(graph3);

    ariel::Graph g4;
    std::vector<std::vector<int>> graph4 = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };
    g4.loadGraph(graph4);

    // בדיקות עבור האופרטור >
    CHECK(g1 > g3);  // סכום g1 גדול מסכום g3
    CHECK(!(g1 > g2));  // g1 ו-g2 שווים

    // בדיקות עבור האופרטור <=
    CHECK(g3 <= g1);  // סכום g3 קטן מסכום g1
    CHECK(g1 <= g2);  // g1 ו-g2 שווים

    // בדיקות עבור האופרטור >=
    CHECK(g1 >= g3);  // סכום g1 גדול מסכום g3
    CHECK(g1 >= g2);  // g1 ו-g2 שווים

    // בדיקות נוספות עבור האופרטור <
    CHECK(g3 < g1);  // סכום g3 קטן מסכום g1
    CHECK(!(g1 < g2));  // g1 ו-g2 שווים
}

TEST_CASE("Test 10: graph prefix increment operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph);

    ++g1;

    std::vector<std::vector<int>> expectedGraph = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };

    CHECK(g1.getMatrix() == expectedGraph);
}
TEST_CASE("Test 11: graph postfix increment operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph);

    ariel::Graph g2 = g1++;

    std::vector<std::vector<int>> expectedGraphG1 = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };

    std::vector<std::vector<int>> expectedGraphG2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    CHECK(g1.getMatrix() == expectedGraphG1);
    CHECK(g2.getMatrix() == expectedGraphG2);
}

TEST_CASE("Test 12: graph prefix decrement operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };
    g1.loadGraph(graph);

    --g1;

    std::vector<std::vector<int>> expectedGraph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    CHECK(g1.getMatrix() == expectedGraph);
}

TEST_CASE("Test 13: graph postfix decrement operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };
    g1.loadGraph(graph);

    ariel::Graph g2 = g1--;

    std::vector<std::vector<int>> expectedGraphG1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> expectedGraphG2 = {
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    };

    CHECK(g1.getMatrix() == expectedGraphG1);
    CHECK(g2.getMatrix() == expectedGraphG2);
}

TEST_CASE("Test 14: graph multiplication by scalar operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph);

    g1 *= 2;

    std::vector<std::vector<int>> expectedGraph = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    };

    CHECK(g1.getMatrix() == expectedGraph);
}

TEST_CASE("Test 15: graph multiplication operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {1, 2},
        {3, 4}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {5, 6},
        {7, 8}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 * g2;

    std::vector<std::vector<int>> expectedGraph = {
        {19, 22},
        {43, 50}
    };

    CHECK(g3.getMatrix() == expectedGraph);
}

TEST_CASE("Test 16: graph division by scalar operator") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    };
    g1.loadGraph(graph);

    g1 /= 2;

    std::vector<std::vector<int>> expectedGraph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    CHECK(g1.getMatrix() == expectedGraph);
}

TEST_CASE("Test 17: graph division by zero or negative scalar throws exception") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    };
    g1.loadGraph(graph);

    CHECK_THROWS_AS(g1 /= 0, std::invalid_argument);
    CHECK_THROWS_AS(g1 /= -1, std::invalid_argument);
}

//matrix with different size

TEST_CASE("Test 18: graph addition throws error for different dimensions") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {1, 2, 3, 4},
        {3, 4, 5, 6},
        {5, 6, 7, 8},
        {5, 6, 7, 8}
    };
    g2.loadGraph(graph2);
    CHECK_THROWS_AS(g1 + g2, std::invalid_argument);

}

TEST_CASE("Test 19: graph subtraction throws error for different dimensions") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {1, 2, 3, 4},
        {3, 4, 5, 6},
        {5, 6, 7, 8},
        {5, 6, 7, 8}
    };
    g2.loadGraph(graph2);
    CHECK_THROWS_AS(g1 - g2, std::invalid_argument);
}

TEST_CASE("Test 20: graph multiplication  throws error for different dimensions") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {1, 2},
        {3, 4}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g2.loadGraph(graph2);

    CHECK_THROWS_AS(g1 * g2, std::invalid_argument);
}
