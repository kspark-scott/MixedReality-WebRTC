// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license
// information.

#include "../include/api.h"

class PCRaii {
 public:
  PCRaii() {
    PeerConnectionConfiguration config;
    config.ice_server_urls = "stun:stun.l.google.com:19302";
    config.num_ice_server_urls = 1;
    uint32_t res = mrsPeerConnectionCreate(config, &handle_);
    if (res != 0) {
      if (handle_ != nullptr) {
        mrsPeerConnectionClose(&handle_);
      }
    }
  }
  ~PCRaii() {
    if (handle_ != nullptr) {
      mrsPeerConnectionClose(&handle_);
    }
  }
  PeerConnectionHandle handle() const { return handle_; }

 protected:
  PeerConnectionHandle handle_{};
};
