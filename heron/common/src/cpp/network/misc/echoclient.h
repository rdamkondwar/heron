#ifndef __ECHOCLIENT_H
#define __ECHOCLIENT_H

#include "network/network.h"
#include "basics/sptypes.h"
#include "network/tests.pb.h"

/* #include "network/event_loop_impl.h" */
/* #include "network/client.h" */
/* #include "network/networkoptions.h" */
/* #include "network_error.h" */
/* #include "basics/sptypes.h" */
/* #include "network/misc/gen/tests.pb.h" */
/* #include "gen/tests.pb.h" */
/* #include "../event_loop_impl.h" */
/* #include "../client.h" */
/* #include "../networkoptions.h" */
/* #include "../network_erro.h" */
/* #include "../../basics/sptypes.h" */

class EchoClient : public Client
{
 public:
  EchoClient(EventLoopImpl* ss, const NetworkOptions& options, bool _perf);
  ~EchoClient();

 protected:
  virtual void HandleConnect(NetworkErrorCode status);
  virtual void HandleClose(NetworkErrorCode status);

 private:
  void HandleEchoResponse(void*, EchoServerResponse* response,
                          NetworkErrorCode status);
  void CreateAndSendRequest();
  sp_int32 nrequests_;
  bool perf_;
};

#endif
