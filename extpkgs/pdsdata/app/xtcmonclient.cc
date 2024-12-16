#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "XtcMonitorClient.hh"

class MyMonitorClient : public Pds::XtcMonitorClient {
public:
  MyMonitorClient(int rate) : _rate(rate) {}
  int processDgram(Pds::Dgram* dg) {
    if (_rate) {
      timespec ts;
      ts.tv_sec  = 0;
      ts.tv_nsec = 1000000000/_rate;
      nanosleep(&ts,0);
    }
    return Pds::XtcMonitorClient::processDgram(dg);
  }
private:
  int _rate;
};

void usage(char* progname) {
  fprintf(stderr,"Usage: %s [-p <partitionTag>] [-i <index>] [-h]\n", progname);
}


int main(int argc, char* argv[]) {
  int c;
  const char* partitionTag = 0;
  unsigned index = 0;
  int rate = 0;

  while ((c = getopt(argc, argv, "?hi:p:r:")) != -1) {
    switch (c) {
    case '?':
    case 'h':
      usage(argv[0]);
      exit(0);
    case 'i':
      index = strtoul(optarg,NULL,0);
      break;
    case 'r':
      rate = strtoul(optarg,NULL,0);
      break;
    case 'p':
      partitionTag = optarg;
      break;
    default:
      usage(argv[0]);
    }
  }

  MyMonitorClient myClient(rate);
  fprintf(stderr, "myClient returned: %d\n", myClient.run(partitionTag,index,index));
  
  return 1;
}
