#ifndef _INTERCONNECT_HPP_
#define _INTERCONNECT_HPP_

#include <list>
#include <map>
#include <set>
#include <cassert>

#include "module.hpp"
#include "config_utils.hpp"
#include "booksim.hpp"
#include "routefunc.hpp"
#include "traffic.hpp"
#include "booksim_config.hpp"
#include "trafficmanager.hpp"
#include "random_utils.hpp"
#include "networks/network.hpp"
#include "injection.hpp"
//#include "gemdroid/gemdroid.hh"
//#define IP_TYPE_END 16 

using namespace std;

class GemDroid;
class Stats_bksim;

class booksim_msg {

public:
 int src;
 int dest;
 booksim_msg(int src, int dest) {this->src = src; this->dest = dest;}
 inline int getsrc() {return src;}
 inline int getdest() {return dest;}
};

extern TrafficManager * trafficManager;

class Interconnect {

protected:
  GemDroid *gemDroid;

public:
  //GemDroid *gemDroid;
  //TrafficManager * trafficManager = NULL;
  Interconnect();
  int init(GemDroid *gemDroid);
  bool Simulate(BookSimConfig const & config, GemDroid *gemDroid);
  int GetSimTime();
  Stats_bksim * GetStats(const std::string & name);
  
  list<booksim_msg> ipipResp_frmbksim[16];
  list<booksim_msg> ipMemReq_frmbksim[16];
  list<booksim_msg> memIpResp_frmbksim[16];

};

#endif
