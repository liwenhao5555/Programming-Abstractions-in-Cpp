/*
 * Function: initAirlineGraph
 * Usage: initAirlineGraph(airline);
 * ---------------------------------
 * Initializes the airline graph to hold the flight data from Figure 19-2.
 * In a real application, the program would almost certainly read this
 * information from a data file.
 */

void initAirlineGraph(Graph<City,Flight> & airline) {
   addCity(airline, "Atlanta", "ATL");
   addCity(airline, "Boston", "BOS");
   addCity(airline, "Chicago", "ORD");
   addCity(airline, "Dallas", "DFW");
   addCity(airline, "Denver", "DEN");
   addCity(airline, "Los Angeles", "LAX");
   addCity(airline, "New York", "JFK");
   addCity(airline, "Portland", "PDX");
   addCity(airline, "San Francisco", "SFO");
   addCity(airline, "Seattle", "SEA");
   addFlight(airline, "Atlanta", "Chicago", 599);
   addFlight(airline, "Atlanta", "Dallas", 725);
   addFlight(airline, "Atlanta", "New York", 756);
   addFlight(airline, "Boston", "New York", 191);
   addFlight(airline, "Boston", "Seattle", 2489);
   addFlight(airline, "Chicago", "Denver", 907);
   addFlight(airline, "Dallas", "Denver", 650);
   addFlight(airline, "Dallas", "Los Angeles", 1240);
   addFlight(airline, "Dallas", "San Francisco", 1468);
   addFlight(airline, "Denver", "San Francisco", 954);
   addFlight(airline, "Portland", "San Francisco", 550);
   addFlight(airline, "Portland", "Seattle", 130);
}

/*
 * Function: addFlight
 * Usage: addFlight(airline, c1, c2, miles);
 * -----------------------------------------
 * Adds an arc in each direction between the cities c1 and c2.
 */

void addFlight(Graph<City,Flight> & airline, string c1, string c2, int miles) {
   airline.addArc(c1, c2)->setCost(miles);
   airline.addArc(c2, c1)->setCost(miles);
}

/*
 * Function: addCity
 * Usage: addCity(g, name, code);
 * ------------------------------
 * Adds a new node with the specified name and airport code to the graph.
 */

void addCity(Graph<City,Flight> & g, string name, string code) {
   City *city = g.addNode(name);
   city->setCode(code);
}
