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

#ifndef __ECHOSERVER_H
#define __ECHOSERVER_H

#include "network/tests.pb.h"
#include "network/network.h"

class EchoServer : public Server {
 public:
  EchoServer(EventLoopImpl* ss, const NetworkOptions& options);
  ~EchoServer();

 protected:
  virtual void HandleNewConnection(Connection* newConnection);
  virtual void HandleConnectionClose(Connection* connection, NetworkErrorCode status);
  virtual void HandleEchoRequest(REQID id, Connection* connection,
                                 EchoServerRequest* request);
};

#endif
