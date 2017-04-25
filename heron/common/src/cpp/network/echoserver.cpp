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

#include "network/echoserver.h"
#include <iostream>

EchoServer::EchoServer(EventLoopImpl* eventLoop, const NetworkOptions& _options)
  : Server(eventLoop, _options) {
  InstallRequestHandler(&EchoServer::HandleEchoRequest);
}

EchoServer::~EchoServer() {
}

void EchoServer::HandleNewConnection(Connection* conn) {
  std::cout << "EchoServer accepting new connection\n";
}

void EchoServer::HandleConnectionClose(Connection* conn, NetworkErrorCode _status) {
  std::cout << "Connection dropped from echoserver with status " << _status << "\n";
}

void EchoServer::HandleEchoRequest(REQID _id, Connection* _connection,
                                   EchoServerRequest* _request) {
  std::cout << "Got a echo request " << _request->echo_request() << std::endl;
  EchoServerResponse response;
  response.set_echo_response(_request->echo_request());
  SendResponse(_id, _connection, response);
  delete _request;
}
