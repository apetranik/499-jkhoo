#ifndef CPP_KEY_VALUE_STORE_SERVICE_IMPL_H_
#define CPP_KEY_VALUE_STORE_SERVICE_IMPL_H_
#include <deque>
#include <map>
#include <mutex>
#include <string>

#include <grpcpp/grpcpp.h>
#include "backendStore.grpc.pb.h"
#include "key_value_store.h"

// Class for logic and data behind the KeyValueStore
// The methods in this class are the implementation of the Key Value Store
// Service from backendStore.proto and forwards the request to the KeyValueStore
// data structure
class KeyValueStoreServiceImpl final : public chirp::KeyValueStore::Service {
 public:
  // grpc function for put, returns a status on whether or not it was successful
  grpc::Status put(grpc::ServerContext* context,
                   const chirp::PutRequest* request,
                   chirp::PutReply* reply) override;
  // grpc function for get, returns a status on whether or not it was successful
  grpc::Status get(grpc::ServerContext* context,
                   grpc::ServerReaderWriter<chirp::GetReply, chirp::GetRequest>*
                       stream) override;
  // grpc function for deletekey, returns a status on whether or not it was
  // successful
  grpc::Status deletekey(grpc::ServerContext* context,
                         const chirp::DeleteRequest* request,
                         chirp::DeleteReply* reply) override;

 private:
  // Data structure behind the key value store
  KeyValueStore value_store_;
};
#endif
