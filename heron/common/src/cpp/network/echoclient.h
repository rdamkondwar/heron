/*
 * Copyright 2015 Twitter, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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

class EchoClient : public Client {
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
