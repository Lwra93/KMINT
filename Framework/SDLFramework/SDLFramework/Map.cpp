#pragma once
#include "Map.h"
#include <ctime>
#include <cmath>

Map::Map()
{
	srand(time(NULL));
}

Map::~Map()
{
	for (auto vertex : this->vertexes)
		delete(vertex);

	for (auto edge : this->edges)
		delete(edge);
}

void Map::addVertex(Vertex* v)
{
	this->vertexes.push_back(v);
}

void Map::addEdge(Edge* e)
{
	this->edges.push_back(e);
}

void Map::draw(FWApplication &application)
{
	
	application.SetColor(Color(0, 0, 0, 255));
	for(auto edge : this->edges)
	{
		int x1 = edge->getVertexes()[0]->getX();
		int x2 = edge->getVertexes()[1]->getX();
		int y1 = edge->getVertexes()[0]->getY();
		int y2 = edge->getVertexes()[1]->getY();
		application.DrawLine(x1, y1, x2, y2);
	}

	application.SetColor(Color(0, 0, 0, 255));
	for (auto vertex : this->vertexes)
		application.DrawCircle(vertex->getX(), vertex->getY(), 5, true);


}

void Map::load()
{
	auto vertex103 = new Vertex(28, 31);
	addVertex(vertex103);
	auto vertex104 = new Vertex(60, 49);
	addVertex(vertex104);
	auto vertex105 = new Vertex(15, 76);
	addVertex(vertex105);
	auto vertex106 = new Vertex(39, 96);
	addVertex(vertex106);
	auto vertex107 = new Vertex(141, 97);
	addVertex(vertex107);
	auto vertex108 = new Vertex(129, 30);
	addVertex(vertex108);
	auto vertex109 = new Vertex(186, 64);
	addVertex(vertex109);
	auto vertex110 = new Vertex(201, 15);
	addVertex(vertex110);
	auto vertex111 = new Vertex(258, 49);
	addVertex(vertex111);
	auto vertex112 = new Vertex(213, 78);
	addVertex(vertex112);
	auto vertex113 = new Vertex(241, 94);
	addVertex(vertex113);
	auto vertex114 = new Vertex(216, 106);
	addVertex(vertex114);
	auto vertex115 = new Vertex(312, 157);
	addVertex(vertex115);
	auto vertex116 = new Vertex(289, 172);
	addVertex(vertex116);
	auto vertex117 = new Vertex(444, 235);
	addVertex(vertex117);
	auto vertex118 = new Vertex(487, 202);
	addVertex(vertex118);
	auto vertex119 = new Vertex(457, 186);
	addVertex(vertex119);
	auto vertex120 = new Vertex(483, 169);
	addVertex(vertex120);
	auto vertex121 = new Vertex(526, 138);
	addVertex(vertex121);
	auto vertex122 = new Vertex(556, 156);
	addVertex(vertex122);
	auto vertex123 = new Vertex(435, 96);
	addVertex(vertex123);
	auto vertex124 = new Vertex(408, 82);
	addVertex(vertex124);
	auto vertex125 = new Vertex(488, 61);
	addVertex(vertex125);
	auto vertex126 = new Vertex(399, 121);
	addVertex(vertex126);
	auto vertex127 = new Vertex(367, 108);
	addVertex(vertex127);
	auto vertex128 = new Vertex(346, 122);
	addVertex(vertex128);
	auto vertex129 = new Vertex(288, 91);
	addVertex(vertex129);
	auto vertex130 = new Vertex(351, 46);
	addVertex(vertex130);
	auto vertex131 = new Vertex(301, 15);
	addVertex(vertex131);
	auto vertex132 = new Vertex(402, 15);
	addVertex(vertex132);
	auto vertex133 = new Vertex(547, 18);
	addVertex(vertex133);
	auto vertex134 = new Vertex(531, 33);
	addVertex(vertex134);
	auto vertex135 = new Vertex(562, 49);
	addVertex(vertex135);
	auto vertex136 = new Vertex(541, 64);
	addVertex(vertex136);
	auto vertex137 = new Vertex(567, 79);
	addVertex(vertex137);
	auto vertex138 = new Vertex(544, 93);
	addVertex(vertex138);
	auto vertex139 = new Vertex(574, 112);
	addVertex(vertex139);
	auto vertex140 = new Vertex(568, 220);
	addVertex(vertex140);
	auto vertex141 = new Vertex(570, 250);
	addVertex(vertex141);
	auto vertex142 = new Vertex(543, 234);
	addVertex(vertex142);
	auto vertex143 = new Vertex(499, 264);
	addVertex(vertex143);
	auto vertex144 = new Vertex(553, 297);
	addVertex(vertex144);
	auto vertex145 = new Vertex(486, 341);
	addVertex(vertex145);
	auto vertex146 = new Vertex(430, 310);
	addVertex(vertex146);
	auto vertex147 = new Vertex(406, 327);
	addVertex(vertex147);
	auto vertex148 = new Vertex(376, 307);
	addVertex(vertex148);
	auto vertex149 = new Vertex(331, 345);
	addVertex(vertex149);
	auto vertex150 = new Vertex(297, 295);
	addVertex(vertex150);
	auto vertex151 = new Vertex(255, 325);
	addVertex(vertex151);
	auto vertex152 = new Vertex(274, 312);
	addVertex(vertex152);
	auto vertex153 = new Vertex(216, 280);
	addVertex(vertex153);
	auto vertex154 = new Vertex(147, 328);
	addVertex(vertex154);
	auto vertex155 = new Vertex(264, 393);
	addVertex(vertex155);
	auto vertex156 = new Vertex(229, 170);
	addVertex(vertex156);
	auto vertex157 = new Vertex(201, 154);
	addVertex(vertex157);
	auto vertex158 = new Vertex(178, 174);
	addVertex(vertex158);
	auto vertex159 = new Vertex(151, 156);
	addVertex(vertex159);
	auto vertex160 = new Vertex(162, 187);
	addVertex(vertex160);
	auto vertex161 = new Vertex(135, 201);
	addVertex(vertex161);
	auto vertex162 = new Vertex(108, 183);
	addVertex(vertex162);
	auto vertex163 = new Vertex(13, 187);
	addVertex(vertex163);
	auto vertex164 = new Vertex(144, 267);
	addVertex(vertex164);
	auto vertex165 = new Vertex(16, 357);
	addVertex(vertex165);
	auto vertex166 = new Vertex(70, 391);
	addVertex(vertex166);
	auto vertex167 = new Vertex(40, 411);
	addVertex(vertex167);
	auto vertex168 = new Vertex(61, 421);
	addVertex(vertex168);
	auto vertex169 = new Vertex(33, 438);
	addVertex(vertex169);
	auto vertex170 = new Vertex(63, 450);
	addVertex(vertex170);
	auto vertex171 = new Vertex(37, 466);
	addVertex(vertex171);
	auto vertex172 = new Vertex(97, 499);
	addVertex(vertex172);
	auto vertex173 = new Vertex(36, 544);
	addVertex(vertex173);
	auto vertex174 = new Vertex(109, 558);
	addVertex(vertex174);
	auto vertex175 = new Vertex(57, 528);
	addVertex(vertex175);
	auto vertex176 = new Vertex(156, 528);
	addVertex(vertex176);
	auto vertex177 = new Vertex(142, 472);
	addVertex(vertex177);
	auto vertex178 = new Vertex(112, 453);
	addVertex(vertex178);
	auto vertex179 = new Vertex(181, 402);
	addVertex(vertex179);
	auto vertex180 = new Vertex(244, 438);
	addVertex(vertex180);
	auto vertex181 = new Vertex(291, 406);
	addVertex(vertex181);
	auto vertex182 = new Vertex(387, 373);
	addVertex(vertex182);
	auto vertex183 = new Vertex(415, 391);
	addVertex(vertex183);
	auto vertex184 = new Vertex(387, 408);
	addVertex(vertex184);
	auto vertex185 = new Vertex(316, 451);
	addVertex(vertex185);
	auto vertex186 = new Vertex(442, 438);
	addVertex(vertex186);
	auto vertex187 = new Vertex(465, 421);
	addVertex(vertex187);
	auto vertex188 = new Vertex(487, 400);
	addVertex(vertex188);
	auto vertex189 = new Vertex(493, 436);
	addVertex(vertex189);
	auto vertex190 = new Vertex(540, 438);
	addVertex(vertex190);
	auto vertex191 = new Vertex(571, 424);
	addVertex(vertex191);
	auto vertex192 = new Vertex(543, 406);
	addVertex(vertex192);
	auto vertex193 = new Vertex(571, 394);
	addVertex(vertex193);
	auto vertex194 = new Vertex(538, 372);
	addVertex(vertex194);
	auto vertex195 = new Vertex(564, 358);
	addVertex(vertex195);
	auto vertex196 = new Vertex(351, 267);
	addVertex(vertex196);
	auto vertex197 = new Vertex(373, 249);
	addVertex(vertex197);
	auto vertex198 = new Vertex(402, 265);
	addVertex(vertex198);
	auto vertex199 = new Vertex(294, 232);
	addVertex(vertex199);
	auto vertex200 = new Vertex(316, 219);
	addVertex(vertex200);
	auto vertex201 = new Vertex(264, 216);
	addVertex(vertex201);
	auto vertex202 = new Vertex(238, 237);
	addVertex(vertex202);
	auto vertex203 = new Vertex(211, 219);
	addVertex(vertex203);
	auto vertex204 = new Vertex(352, 577);
	addVertex(vertex204);
	auto vertex205 = new Vertex(261, 529);
	addVertex(vertex205);
	auto vertex206 = new Vertex(303, 499);
	addVertex(vertex206);
	auto vertex207 = new Vertex(245, 469);
	addVertex(vertex207);
	auto vertex211 = new Vertex(87, 61);
	addVertex(vertex211);
	auto vertex306 = new Vertex(345, 468);
	addVertex(vertex306);
	auto vertex322 = new Vertex(213, 562);
	addVertex(vertex322);
	auto vertex325 = new Vertex(190, 576);
	addVertex(vertex325);
	auto vertex327 = new Vertex(384, 555); // Dit is de basis rechtsonder
	addVertex(vertex327);
	addEdge(new Edge(vertex103, vertex104));
	addEdge(new Edge(vertex106, vertex105));
	addEdge(new Edge(vertex104, vertex105));
	addEdge(new Edge(vertex211, vertex104));
	addEdge(new Edge(vertex211, vertex108));
	addEdge(new Edge(vertex211, vertex107));
	addEdge(new Edge(vertex107, vertex109));
	addEdge(new Edge(vertex109, vertex112));
	addEdge(new Edge(vertex112, vertex111));
	addEdge(new Edge(vertex111, vertex111));
	addEdge(new Edge(vertex113, vertex112));
	addEdge(new Edge(vertex113, vertex114));
	addEdge(new Edge(vertex114, vertex115));
	addEdge(new Edge(vertex115, vertex116));
	addEdge(new Edge(vertex115, vertex117));
	addEdge(new Edge(vertex117, vertex198));
	addEdge(new Edge(vertex198, vertex197));
	addEdge(new Edge(vertex197, vertex196));
	addEdge(new Edge(vertex196, vertex199));
	addEdge(new Edge(vertex199, vertex200));
	addEdge(new Edge(vertex199, vertex201));
	addEdge(new Edge(vertex201, vertex202));
	addEdge(new Edge(vertex202, vertex203));
	addEdge(new Edge(vertex203, vertex160));
	addEdge(new Edge(vertex160, vertex158));
	addEdge(new Edge(vertex158, vertex159));
	addEdge(new Edge(vertex158, vertex157));
	addEdge(new Edge(vertex157, vertex156));
	addEdge(new Edge(vertex160, vertex161));
	addEdge(new Edge(vertex161, vertex162));
	addEdge(new Edge(vertex107, vertex163));
	addEdge(new Edge(vertex163, vertex164));
	addEdge(new Edge(vertex129, vertex130));
	addEdge(new Edge(vertex128, vertex129));
	addEdge(new Edge(vertex128, vertex127));
	addEdge(new Edge(vertex127, vertex126));
	addEdge(new Edge(vertex126, vertex123));
	addEdge(new Edge(vertex123, vertex124));
	addEdge(new Edge(vertex123, vertex125));
	addEdge(new Edge(vertex134, vertex135));
	addEdge(new Edge(vertex135, vertex136));
	addEdge(new Edge(vertex136, vertex137));
	addEdge(new Edge(vertex137, vertex138));
	addEdge(new Edge(vertex138, vertex139));
	addEdge(new Edge(vertex139, vertex121));
	addEdge(new Edge(vertex121, vertex122));
	addEdge(new Edge(vertex121, vertex123));
	addEdge(new Edge(vertex121, vertex120));
	addEdge(new Edge(vertex120, vertex119));
	addEdge(new Edge(vertex119, vertex118));
	addEdge(new Edge(vertex118, vertex117));
	addEdge(new Edge(vertex118, vertex142));
	addEdge(new Edge(vertex142, vertex140));
	addEdge(new Edge(vertex142, vertex141));
	addEdge(new Edge(vertex142, vertex143));
	addEdge(new Edge(vertex143, vertex144));
	addEdge(new Edge(vertex144, vertex145));
	addEdge(new Edge(vertex145, vertex146));
	addEdge(new Edge(vertex146, vertex147));
	addEdge(new Edge(vertex147, vertex148));
	addEdge(new Edge(vertex148, vertex149));
	addEdge(new Edge(vertex149, vertex152));
	addEdge(new Edge(vertex152, vertex150));
	addEdge(new Edge(vertex152, vertex151));
	addEdge(new Edge(vertex152, vertex153));
	addEdge(new Edge(vertex153, vertex154));
	addEdge(new Edge(vertex154, vertex166));
	addEdge(new Edge(vertex166, vertex165));
	addEdge(new Edge(vertex165, vertex164));
	addEdge(new Edge(vertex164, vertex203));
	addEdge(new Edge(vertex172, vertex171));
	addEdge(new Edge(vertex171, vertex170));
	addEdge(new Edge(vertex170, vertex169));
	addEdge(new Edge(vertex169, vertex168));
	addEdge(new Edge(vertex167, vertex166));
	addEdge(new Edge(vertex168, vertex167));
	addEdge(new Edge(vertex173, vertex175));
	addEdge(new Edge(vertex172, vertex175));
	addEdge(new Edge(vertex177, vertex172));
	addEdge(new Edge(vertex178, vertex177));
	addEdge(new Edge(vertex178, vertex179));
	addEdge(new Edge(vertex179, vertex180));
	addEdge(new Edge(vertex155, vertex181));
	addEdge(new Edge(vertex155, vertex149));
	addEdge(new Edge(vertex155, vertex154));
	addEdge(new Edge(vertex183, vertex182));
	addEdge(new Edge(vertex183, vertex184));
	addEdge(new Edge(vertex183, vertex145));
	addEdge(new Edge(vertex145, vertex194));
	addEdge(new Edge(vertex194, vertex195));
	addEdge(new Edge(vertex194, vertex193));
	addEdge(new Edge(vertex193, vertex192));
	addEdge(new Edge(vertex192, vertex191));
	addEdge(new Edge(vertex188, vertex187));
	addEdge(new Edge(vertex184, vertex185));
	addEdge(new Edge(vertex205, vertex204));
	addEdge(new Edge(vertex205, vertex206));
	addEdge(new Edge(vertex185, vertex306));
	addEdge(new Edge(vertex206, vertex306));
	addEdge(new Edge(vertex207, vertex206));
	addEdge(new Edge(vertex176, vertex207));
	addEdge(new Edge(vertex176, vertex174));
	addEdge(new Edge(vertex174, vertex175));
	addEdge(new Edge(vertex187, vertex186));
	addEdge(new Edge(vertex187, vertex189));
	addEdge(new Edge(vertex186, vertex184));
	addEdge(new Edge(vertex191, vertex190));
	addEdge(new Edge(vertex111, vertex110));
	addEdge(new Edge(vertex130, vertex131));
	addEdge(new Edge(vertex130, vertex132));
	addEdge(new Edge(vertex132, vertex125));
	addEdge(new Edge(vertex133, vertex134));
	addEdge(new Edge(vertex322, vertex176));
	addEdge(new Edge(vertex180, vertex181));
	addEdge(new Edge(vertex325, vertex322));
	addEdge(new Edge(vertex204, vertex327));

	addConnectionsVertexes();
}

Vertex* Map::randomVertex(Vertex* current) const
{

	auto loc = current;

	while(loc == current)
	{
		
		auto index = rand() % vertexes.size();
		loc = vertexes[index];
	}

	

	return loc;

}

Vertex* Map::getVertex(int location) const
{
	return vertexes.at(location);
}

void Map::resetCosts()
{
	for (auto vertex : vertexes)
		vertex->resetCost();
}

vector<Vertex*> Map::getVertexes()
{
	return vertexes;
}

void Map::addConnectionsVertexes()
{
	for(auto v : vertexes)
	{
		auto tempEdges = v->getEdges();
		for(auto e : v->getEdges())
		{
			auto tempNeighbours = e->getVertexes();

			for (auto temp : e->getVertexes())
			{
				
				if (temp->getX() != v->getX() || temp->getY() != v->getY())
				{
					v->connections.push_back(temp);
				}
			}
		}
		
	}


	
}
