//
// Created by lixiaoqing on 2023/7/17.
//

#include "pb_helper.h"

#include <iostream>

#include "google/protobuf/text_format.h"
#include "google/protobuf/util/json_util.h"

#define log(format, ...) { printf(format, ##__VA_ARGS__); printf("\n"); }


bool PbHelper::ToBinary(const google::protobuf::Message &message, std::string &output) {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    bool flag = message.SerializeToString(&output);

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return flag;
}

bool PbHelper::ToString(const google::protobuf::Message &message, std::string &output) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
//    output = message.DebugString();
    return google::protobuf::TextFormat::PrintToString(message, &output);
}

bool PbHelper::ToJson(const google::protobuf::Message &message, std::string &output) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    google::protobuf::util::JsonPrintOptions options;
//    options.add_whitespace = true;
    options.preserve_proto_field_names = true;
    options.always_print_enums_as_ints = true;
    options.always_print_primitive_fields = true;
    return google::protobuf::util::MessageToJsonString(message, &output, options).ok();
}

bool PbHelper::ParseFromBinary(const std::string &input, google::protobuf::Message &message) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    return message.ParseFromString(input);
}

bool PbHelper::ParseFromJson(const std::string &input, google::protobuf::Message &message) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    google::protobuf::util::JsonParseOptions options;
    return google::protobuf::util::JsonStringToMessage(input, &message, options).ok();
}






