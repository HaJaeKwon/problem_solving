#include <boost/config.hpp>
#include <iostream>
#include <fstream>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;

int main(int, char*[]) {

	// ����ġ ����Ʈ �׷��� Ÿ�Լ���
	typedef adjacency_list < listS, vecS, directedS, no_property, property < edge_weight_t, int > > graph_t;
	typedef adjacency_list < listS, vecS, directedS, no_property, property < edge_weight_t, int > > graph_t;
	// vertex �� edge Ÿ�� ����
	typedef graph_traits < graph_t >::vertex_descriptor vertex_descriptor;
	typedef graph_traits < graph_t >::edge_descriptor edge_descriptor;
	typedef std::pair<int, int> Edge;
	
	// vertex ����
	const int num_nodes = 5;
	enum nodes { A, B, C, D, E };
	char name[] = "ABCDE";
	// edge ����
	Edge edge_array[] = { Edge(A, C), Edge(B, B), Edge(B, D), Edge(B, E), Edge(C, B), Edge(C, D), Edge(D, E), Edge(E, A), Edge(E, B) };
	// weight ����
	int weights[] = { 1, 2, 1, 2, 7, 3, 1, 1, 1 };
	// edge ���� ����
	int num_arcs = sizeof(edge_array) / sizeof(Edge);

	// �������� ���� �Է�
	char a,b;
	int st,ds;
	std::cout<<"�˻��� �ִܰ���� �������� ������ �Է��ϼ���. ex) A D"<< std::endl;
	std::cin>>a;
	std::cin>>b;

	// �Է¹��� �������� ������ ���ڷ� ����
	if(a=='A') st=A;
	if(a=='B') st=B;
	if(a=='C') st=C;
	if(a=='D') st=D;
	if(a=='E') st=E;
	if(b=='A') ds=A;
	if(b=='B') ds=B;
	if(b=='C') ds=C;
	if(b=='D') ds=D;
	if(b=='E') ds=E;

#if defined(BOOST_MSVC) && BOOST_MSVC <= 1300
	graph_t g(num_nodes);
	property_map<graph_t, edge_weight_t>::type weightmap = get(edge_weight, g);
	for (std::size_t j = 0; j < num_arcs; ++j) {
		edge_descriptor e;
		bool inserted;
		boost::tie(e, inserted) = add_edge(edge_array[j].first, edge_array[j].second, g);
		weightmap[e] = weights[j];
	}
#else
	graph_t g(edge_array, edge_array + num_arcs, weights, num_nodes);
	// property_map �� ����� edge_weight�� ����
	property_map<graph_t, edge_weight_t>::type weightmap = get(edge_weight, g);
#endif
	// �θ� vertex�� �����ϴ� p ����
	std::vector<vertex_descriptor> p(num_vertices(g));
	// �Ÿ��� �����ϴ� d ����
	std::vector<int> d(num_vertices(g));
	vertex_descriptor s = vertex(st, g);

#if defined(BOOST_MSVC) && BOOST_MSVC <= 1300
	// VC++ has trouble with the named parameters mechanism
	property_map<graph_t, vertex_index_t>::type indexmap = get(vertex_index, g);
	dijkstra_shortest_paths(g, s, &p[0], &d[0], weightmap, indexmap, 
                          std::less<int>(), closed_plus<int>(), 
                          (std::numeric_limits<int>::max)(), 0,
                          default_dijkstra_visitor());
#else
	// s ���� ���� �����Ͽ� �ִܰ�� ���
	dijkstra_shortest_paths(g, s, predecessor_map(&p[0]).distance_map(&d[0]));
#endif

	
	std::cout << "���� <- ������" << std::endl;
	graph_traits < graph_t >::vertex_iterator vi, vend;
	for (boost::tie(vi, vend) = vertices(g); vi != vend; ++vi) {
		// �������� ã�Ҵٸ� ������ ����
		if(*vi==ds) {
			// ������ ���
			std::cout << name[*vi] << " <- ";
			int temp = p[*vi];
			while(temp!=st) {
				// �� ���� �湮 vertex ���
				std::cout << name[temp] << " <- ";
				temp = p[temp];
			}
			// ������ ���
			std::cout << name[temp];
			break;
		}
	}
	std::cout << std::endl;
	
	system("pause");
	return EXIT_SUCCESS;
}