/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "Unicap_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace ntu {
namespace cap {

int _kStorageTypeValues[] = {
    StorageType::InMemoryKeyValue,
    StorageType::LSMKeyValue,
    StorageType::OnDiskKeyValue,
    StorageType::InMemoryImage,
    StorageType::DenseMatrix,
    StorageType::SparseMatrix,
    StorageType::HdfsKeyValue
};
const char* _kStorageTypeNames[] = {
    "InMemoryKeyValue",
    "LSMKeyValue",
    "OnDiskKeyValue",
    "InMemoryImage",
    "DenseMatrix",
    "SparseMatrix",
    "HdfsKeyValue"
};
const std::map<int, const char*> _StorageType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(7, _kStorageTypeValues, _kStorageTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kValueTypeValues[] = {
    ValueType::Int64,
    ValueType::Double,
    ValueType::String
};
const char* _kValueTypeNames[] = {
    "Int64",
    "Double",
    "String"
};
const std::map<int, const char*> _ValueType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kValueTypeValues, _kValueTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

int _kKeyPartitionAlgoValues[] = {
    KeyPartitionAlgo::NoneAlgo,
    KeyPartitionAlgo::HashingPartition,
    KeyPartitionAlgo::RangePartition
};
const char* _kKeyPartitionAlgoNames[] = {
    "NoneAlgo",
    "HashingPartition",
    "RangePartition"
};
const std::map<int, const char*> _KeyPartitionAlgo_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kKeyPartitionAlgoValues, _kKeyPartitionAlgoNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));


KeyPartition::~KeyPartition() throw() {
}


void KeyPartition::__set_partition_algo(const KeyPartitionAlgo::type val) {
    this->partition_algo = val;
}

void KeyPartition::__set_key_to_shard(const std::map<std::string, int64_t> & val) {
    this->key_to_shard = val;
    __isset.key_to_shard = true;
}

const char* KeyPartition::ascii_fingerprint = "8784C999254F8BB696EB735A27E287C7";
const uint8_t KeyPartition::binary_fingerprint[16] = {0x87,0x84,0xC9,0x99,0x25,0x4F,0x8B,0xB6,0x96,0xEB,0x73,0x5A,0x27,0xE2,0x87,0xC7};

uint32_t KeyPartition::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_partition_algo = false;

    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_I32) {
                int32_t ecast0;
                xfer += iprot->readI32(ecast0);
                this->partition_algo = (KeyPartitionAlgo::type)ecast0;
                isset_partition_algo = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_MAP) {
                {
                    this->key_to_shard.clear();
                    uint32_t _size1;
                    ::apache::thrift::protocol::TType _ktype2;
                    ::apache::thrift::protocol::TType _vtype3;
                    xfer += iprot->readMapBegin(_ktype2, _vtype3, _size1);
                    uint32_t _i5;
                    for (_i5 = 0; _i5 < _size1; ++_i5) {
                        std::string _key6;
                        xfer += iprot->readString(_key6);
                        int64_t& _val7 = this->key_to_shard[_key6];
                        xfer += iprot->readI64(_val7);
                    }
                    xfer += iprot->readMapEnd();
                }
                this->__isset.key_to_shard = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        default:
            xfer += iprot->skip(ftype);
            break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_partition_algo)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t KeyPartition::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("KeyPartition");

    xfer += oprot->writeFieldBegin("partition_algo", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->partition_algo);
    xfer += oprot->writeFieldEnd();

    if (this->__isset.key_to_shard) {
        xfer += oprot->writeFieldBegin("key_to_shard", ::apache::thrift::protocol::T_MAP, 2);
        {
            xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->key_to_shard.size()));
            std::map<std::string, int64_t> ::const_iterator _iter8;
            for (_iter8 = this->key_to_shard.begin(); _iter8 != this->key_to_shard.end(); ++_iter8) {
                xfer += oprot->writeString(_iter8->first);
                xfer += oprot->writeI64(_iter8->second);
            }
            xfer += oprot->writeMapEnd();
        }
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}

void swap(KeyPartition &a, KeyPartition &b) {
    using ::std::swap;
    swap(a.partition_algo, b.partition_algo);
    swap(a.key_to_shard, b.key_to_shard);
    swap(a.__isset, b.__isset);
}

KeyPartition::KeyPartition(const KeyPartition& other9) {
    partition_algo = other9.partition_algo;
    key_to_shard = other9.key_to_shard;
    __isset = other9.__isset;
}
KeyPartition& KeyPartition::operator=(const KeyPartition& other10) {
    partition_algo = other10.partition_algo;
    key_to_shard = other10.key_to_shard;
    __isset = other10.__isset;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const KeyPartition& obj) {
    using apache::thrift::to_string;
    out << "KeyPartition(";
    out << "partition_algo=" << to_string(obj.partition_algo);
    out << ", " << "key_to_shard=";
    (obj.__isset.key_to_shard ? (out << to_string(obj.key_to_shard)) : (out << "<null>"));
    out << ")";
    return out;
}


TaskTrackerInfo::~TaskTrackerInfo() throw() {
}


void TaskTrackerInfo::__set_host_name(const std::string& val) {
    this->host_name = val;
}

void TaskTrackerInfo::__set_port(const int64_t val) {
    this->port = val;
}

const char* TaskTrackerInfo::ascii_fingerprint = "1CCCF6FC31CFD1D61BBBB1BAF3590620";
const uint8_t TaskTrackerInfo::binary_fingerprint[16] = {0x1C,0xCC,0xF6,0xFC,0x31,0xCF,0xD1,0xD6,0x1B,0xBB,0xB1,0xBA,0xF3,0x59,0x06,0x20};

uint32_t TaskTrackerInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_host_name = false;
    bool isset_port = false;

    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->host_name);
                isset_host_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->port);
                isset_port = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        default:
            xfer += iprot->skip(ftype);
            break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_host_name)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_port)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t TaskTrackerInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskTrackerInfo");

    xfer += oprot->writeFieldBegin("host_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->host_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("port", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->port);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}

void swap(TaskTrackerInfo &a, TaskTrackerInfo &b) {
    using ::std::swap;
    swap(a.host_name, b.host_name);
    swap(a.port, b.port);
}

TaskTrackerInfo::TaskTrackerInfo(const TaskTrackerInfo& other11) {
    host_name = other11.host_name;
    port = other11.port;
}
TaskTrackerInfo& TaskTrackerInfo::operator=(const TaskTrackerInfo& other12) {
    host_name = other12.host_name;
    port = other12.port;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const TaskTrackerInfo& obj) {
    using apache::thrift::to_string;
    out << "TaskTrackerInfo(";
    out << "host_name=" << to_string(obj.host_name);
    out << ", " << "port=" << to_string(obj.port);
    out << ")";
    return out;
}


TableProperty::~TableProperty() throw() {
}


void TableProperty::__set_table_name(const std::string& val) {
    this->table_name = val;
}

void TableProperty::__set_shard_num(const int64_t val) {
    this->shard_num = val;
}

void TableProperty::__set_shard_location(const std::map<int64_t, int64_t> & val) {
    this->shard_location = val;
}

void TableProperty::__set_node_info(const std::map<int64_t, std::vector<int64_t> > & val) {
    this->node_info = val;
}

void TableProperty::__set_key_partition(const KeyPartition& val) {
    this->key_partition = val;
}

const char* TableProperty::ascii_fingerprint = "8779CA596893F4FBCFE4B27D10184031";
const uint8_t TableProperty::binary_fingerprint[16] = {0x87,0x79,0xCA,0x59,0x68,0x93,0xF4,0xFB,0xCF,0xE4,0xB2,0x7D,0x10,0x18,0x40,0x31};

uint32_t TableProperty::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_table_name = false;
    bool isset_shard_num = false;
    bool isset_shard_location = false;
    bool isset_node_info = false;
    bool isset_key_partition = false;

    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->table_name);
                isset_table_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->shard_num);
                isset_shard_num = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 3:
            if (ftype == ::apache::thrift::protocol::T_MAP) {
                {
                    this->shard_location.clear();
                    uint32_t _size13;
                    ::apache::thrift::protocol::TType _ktype14;
                    ::apache::thrift::protocol::TType _vtype15;
                    xfer += iprot->readMapBegin(_ktype14, _vtype15, _size13);
                    uint32_t _i17;
                    for (_i17 = 0; _i17 < _size13; ++_i17) {
                        int64_t _key18;
                        xfer += iprot->readI64(_key18);
                        int64_t& _val19 = this->shard_location[_key18];
                        xfer += iprot->readI64(_val19);
                    }
                    xfer += iprot->readMapEnd();
                }
                isset_shard_location = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 4:
            if (ftype == ::apache::thrift::protocol::T_MAP) {
                {
                    this->node_info.clear();
                    uint32_t _size20;
                    ::apache::thrift::protocol::TType _ktype21;
                    ::apache::thrift::protocol::TType _vtype22;
                    xfer += iprot->readMapBegin(_ktype21, _vtype22, _size20);
                    uint32_t _i24;
                    for (_i24 = 0; _i24 < _size20; ++_i24) {
                        int64_t _key25;
                        xfer += iprot->readI64(_key25);
                        std::vector<int64_t> & _val26 = this->node_info[_key25];
                        {
                            _val26.clear();
                            uint32_t _size27;
                            ::apache::thrift::protocol::TType _etype30;
                            xfer += iprot->readListBegin(_etype30, _size27);
                            _val26.resize(_size27);
                            uint32_t _i31;
                            for (_i31 = 0; _i31 < _size27; ++_i31) {
                                xfer += iprot->readI64(_val26[_i31]);
                            }
                            xfer += iprot->readListEnd();
                        }
                    }
                    xfer += iprot->readMapEnd();
                }
                isset_node_info = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 5:
            if (ftype == ::apache::thrift::protocol::T_STRUCT) {
                xfer += this->key_partition.read(iprot);
                isset_key_partition = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        default:
            xfer += iprot->skip(ftype);
            break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_table_name)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_shard_num)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_shard_location)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_node_info)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_key_partition)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t TableProperty::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TableProperty");

    xfer += oprot->writeFieldBegin("table_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->table_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_num", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->shard_num);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("shard_location", ::apache::thrift::protocol::T_MAP, 3);
    {
        xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->shard_location.size()));
        std::map<int64_t, int64_t> ::const_iterator _iter32;
        for (_iter32 = this->shard_location.begin(); _iter32 != this->shard_location.end(); ++_iter32) {
            xfer += oprot->writeI64(_iter32->first);
            xfer += oprot->writeI64(_iter32->second);
        }
        xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("node_info", ::apache::thrift::protocol::T_MAP, 4);
    {
        xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->node_info.size()));
        std::map<int64_t, std::vector<int64_t> > ::const_iterator _iter33;
        for (_iter33 = this->node_info.begin(); _iter33 != this->node_info.end(); ++_iter33) {
            xfer += oprot->writeI64(_iter33->first);
            {
                xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(_iter33->second.size()));
                std::vector<int64_t> ::const_iterator _iter34;
                for (_iter34 = _iter33->second.begin(); _iter34 != _iter33->second.end(); ++_iter34) {
                    xfer += oprot->writeI64((*_iter34));
                }
                xfer += oprot->writeListEnd();
            }
        }
        xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("key_partition", ::apache::thrift::protocol::T_STRUCT, 5);
    xfer += this->key_partition.write(oprot);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}

void swap(TableProperty &a, TableProperty &b) {
    using ::std::swap;
    swap(a.table_name, b.table_name);
    swap(a.shard_num, b.shard_num);
    swap(a.shard_location, b.shard_location);
    swap(a.node_info, b.node_info);
    swap(a.key_partition, b.key_partition);
}

TableProperty::TableProperty(const TableProperty& other35) {
    table_name = other35.table_name;
    shard_num = other35.shard_num;
    shard_location = other35.shard_location;
    node_info = other35.node_info;
    key_partition = other35.key_partition;
}
TableProperty& TableProperty::operator=(const TableProperty& other36) {
    table_name = other36.table_name;
    shard_num = other36.shard_num;
    shard_location = other36.shard_location;
    node_info = other36.node_info;
    key_partition = other36.key_partition;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const TableProperty& obj) {
    using apache::thrift::to_string;
    out << "TableProperty(";
    out << "table_name=" << to_string(obj.table_name);
    out << ", " << "shard_num=" << to_string(obj.shard_num);
    out << ", " << "shard_location=" << to_string(obj.shard_location);
    out << ", " << "node_info=" << to_string(obj.node_info);
    out << ", " << "key_partition=" << to_string(obj.key_partition);
    out << ")";
    return out;
}


ColumnFamilyProperty::~ColumnFamilyProperty() throw() {
}


void ColumnFamilyProperty::__set_cf_name(const std::string& val) {
    this->cf_name = val;
}

void ColumnFamilyProperty::__set_storage_type(const StorageType::type val) {
    this->storage_type = val;
}

void ColumnFamilyProperty::__set_value_type(const ValueType::type val) {
    this->value_type = val;
}

void ColumnFamilyProperty::__set_block_size(const std::vector<int64_t> & val) {
    this->block_size = val;
}

const char* ColumnFamilyProperty::ascii_fingerprint = "E05D11A065D289293DBEC51207844A07";
const uint8_t ColumnFamilyProperty::binary_fingerprint[16] = {0xE0,0x5D,0x11,0xA0,0x65,0xD2,0x89,0x29,0x3D,0xBE,0xC5,0x12,0x07,0x84,0x4A,0x07};

uint32_t ColumnFamilyProperty::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_cf_name = false;
    bool isset_storage_type = false;
    bool isset_value_type = false;
    bool isset_block_size = false;

    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->cf_name);
                isset_cf_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I32) {
                int32_t ecast37;
                xfer += iprot->readI32(ecast37);
                this->storage_type = (StorageType::type)ecast37;
                isset_storage_type = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 3:
            if (ftype == ::apache::thrift::protocol::T_I32) {
                int32_t ecast38;
                xfer += iprot->readI32(ecast38);
                this->value_type = (ValueType::type)ecast38;
                isset_value_type = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 4:
            if (ftype == ::apache::thrift::protocol::T_LIST) {
                {
                    this->block_size.clear();
                    uint32_t _size39;
                    ::apache::thrift::protocol::TType _etype42;
                    xfer += iprot->readListBegin(_etype42, _size39);
                    this->block_size.resize(_size39);
                    uint32_t _i43;
                    for (_i43 = 0; _i43 < _size39; ++_i43) {
                        xfer += iprot->readI64(this->block_size[_i43]);
                    }
                    xfer += iprot->readListEnd();
                }
                isset_block_size = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        default:
            xfer += iprot->skip(ftype);
            break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_cf_name)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_storage_type)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_value_type)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    if (!isset_block_size)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t ColumnFamilyProperty::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("ColumnFamilyProperty");

    xfer += oprot->writeFieldBegin("cf_name", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->cf_name);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("storage_type", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->storage_type);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("value_type", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32((int32_t)this->value_type);
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldBegin("block_size", ::apache::thrift::protocol::T_LIST, 4);
    {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->block_size.size()));
        std::vector<int64_t> ::const_iterator _iter44;
        for (_iter44 = this->block_size.begin(); _iter44 != this->block_size.end(); ++_iter44) {
            xfer += oprot->writeI64((*_iter44));
        }
        xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();

    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}

void swap(ColumnFamilyProperty &a, ColumnFamilyProperty &b) {
    using ::std::swap;
    swap(a.cf_name, b.cf_name);
    swap(a.storage_type, b.storage_type);
    swap(a.value_type, b.value_type);
    swap(a.block_size, b.block_size);
}

ColumnFamilyProperty::ColumnFamilyProperty(const ColumnFamilyProperty& other45) {
    cf_name = other45.cf_name;
    storage_type = other45.storage_type;
    value_type = other45.value_type;
    block_size = other45.block_size;
}
ColumnFamilyProperty& ColumnFamilyProperty::operator=(const ColumnFamilyProperty& other46) {
    cf_name = other46.cf_name;
    storage_type = other46.storage_type;
    value_type = other46.value_type;
    block_size = other46.block_size;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const ColumnFamilyProperty& obj) {
    using apache::thrift::to_string;
    out << "ColumnFamilyProperty(";
    out << "cf_name=" << to_string(obj.cf_name);
    out << ", " << "storage_type=" << to_string(obj.storage_type);
    out << ", " << "value_type=" << to_string(obj.value_type);
    out << ", " << "block_size=" << to_string(obj.block_size);
    out << ")";
    return out;
}


TaskNode::~TaskNode() throw() {
}


void TaskNode::__set_status(const bool val) {
    this->status = val;
}

void TaskNode::__set_stage_id(const int64_t val) {
    this->stage_id = val;
    __isset.stage_id = true;
}

void TaskNode::__set_task_id(const int64_t val) {
    this->task_id = val;
    __isset.task_id = true;
}

void TaskNode::__set_function_name(const std::string& val) {
    this->function_name = val;
    __isset.function_name = true;
}

void TaskNode::__set_src_table_name(const std::string& val) {
    this->src_table_name = val;
    __isset.src_table_name = true;
}

void TaskNode::__set_src_shard_id(const int64_t val) {
    this->src_shard_id = val;
    __isset.src_shard_id = true;
}

void TaskNode::__set_src_cf_name(const std::string& val) {
    this->src_cf_name = val;
    __isset.src_cf_name = true;
}

void TaskNode::__set_dst_table_name(const std::string& val) {
    this->dst_table_name = val;
    __isset.dst_table_name = true;
}

void TaskNode::__set_dst_cf_name(const std::string& val) {
    this->dst_cf_name = val;
    __isset.dst_cf_name = true;
}

void TaskNode::__set_dst_shard_id(const int64_t val) {
    this->dst_shard_id = val;
    __isset.dst_shard_id = true;
}

const char* TaskNode::ascii_fingerprint = "798F338BF6386D059FAE60C04F1048BF";
const uint8_t TaskNode::binary_fingerprint[16] = {0x79,0x8F,0x33,0x8B,0xF6,0x38,0x6D,0x05,0x9F,0xAE,0x60,0xC0,0x4F,0x10,0x48,0xBF};

uint32_t TaskNode::read(::apache::thrift::protocol::TProtocol* iprot) {

    uint32_t xfer = 0;
    std::string fname;
    ::apache::thrift::protocol::TType ftype;
    int16_t fid;

    xfer += iprot->readStructBegin(fname);

    using ::apache::thrift::protocol::TProtocolException;

    bool isset_status = false;

    while (true) {
        xfer += iprot->readFieldBegin(fname, ftype, fid);
        if (ftype == ::apache::thrift::protocol::T_STOP) {
            break;
        }
        switch (fid) {
        case 1:
            if (ftype == ::apache::thrift::protocol::T_BOOL) {
                xfer += iprot->readBool(this->status);
                isset_status = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 2:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->stage_id);
                this->__isset.stage_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 3:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->task_id);
                this->__isset.task_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 4:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->function_name);
                this->__isset.function_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 5:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->src_table_name);
                this->__isset.src_table_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 6:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->src_shard_id);
                this->__isset.src_shard_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 7:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->src_cf_name);
                this->__isset.src_cf_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 8:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->dst_table_name);
                this->__isset.dst_table_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 9:
            if (ftype == ::apache::thrift::protocol::T_STRING) {
                xfer += iprot->readString(this->dst_cf_name);
                this->__isset.dst_cf_name = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        case 10:
            if (ftype == ::apache::thrift::protocol::T_I64) {
                xfer += iprot->readI64(this->dst_shard_id);
                this->__isset.dst_shard_id = true;
            } else {
                xfer += iprot->skip(ftype);
            }
            break;
        default:
            xfer += iprot->skip(ftype);
            break;
        }
        xfer += iprot->readFieldEnd();
    }

    xfer += iprot->readStructEnd();

    if (!isset_status)
        throw TProtocolException(TProtocolException::INVALID_DATA);
    return xfer;
}

uint32_t TaskNode::write(::apache::thrift::protocol::TProtocol* oprot) const {
    uint32_t xfer = 0;
    oprot->incrementRecursionDepth();
    xfer += oprot->writeStructBegin("TaskNode");

    xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_BOOL, 1);
    xfer += oprot->writeBool(this->status);
    xfer += oprot->writeFieldEnd();

    if (this->__isset.stage_id) {
        xfer += oprot->writeFieldBegin("stage_id", ::apache::thrift::protocol::T_I64, 2);
        xfer += oprot->writeI64(this->stage_id);
        xfer += oprot->writeFieldEnd();
    }
    if (this->__isset.task_id) {
        xfer += oprot->writeFieldBegin("task_id", ::apache::thrift::protocol::T_I64, 3);
        xfer += oprot->writeI64(this->task_id);
        xfer += oprot->writeFieldEnd();
    }
    if (this->__isset.function_name) {
        xfer += oprot->writeFieldBegin("function_name", ::apache::thrift::protocol::T_STRING, 4);
        xfer += oprot->writeString(this->function_name);
        xfer += oprot->writeFieldEnd();
    }
    if (this->__isset.src_table_name) {
        xfer += oprot->writeFieldBegin("src_table_name", ::apache::thrift::protocol::T_STRING, 5);
        xfer += oprot->writeString(this->src_table_name);
        xfer += oprot->writeFieldEnd();
    }
    if (this->__isset.src_shard_id) {
        xfer += oprot->writeFieldBegin("src_shard_id", ::apache::thrift::protocol::T_I64, 6);
        xfer += oprot->writeI64(this->src_shard_id);
        xfer += oprot->writeFieldEnd();
    }
    if (this->__isset.src_cf_name) {
        xfer += oprot->writeFieldBegin("src_cf_name", ::apache::thrift::protocol::T_STRING, 7);
        xfer += oprot->writeString(this->src_cf_name);
        xfer += oprot->writeFieldEnd();
    }
    if (this->__isset.dst_table_name) {
        xfer += oprot->writeFieldBegin("dst_table_name", ::apache::thrift::protocol::T_STRING, 8);
        xfer += oprot->writeString(this->dst_table_name);
        xfer += oprot->writeFieldEnd();
    }
    if (this->__isset.dst_cf_name) {
        xfer += oprot->writeFieldBegin("dst_cf_name", ::apache::thrift::protocol::T_STRING, 9);
        xfer += oprot->writeString(this->dst_cf_name);
        xfer += oprot->writeFieldEnd();
    }
    if (this->__isset.dst_shard_id) {
        xfer += oprot->writeFieldBegin("dst_shard_id", ::apache::thrift::protocol::T_I64, 10);
        xfer += oprot->writeI64(this->dst_shard_id);
        xfer += oprot->writeFieldEnd();
    }
    xfer += oprot->writeFieldStop();
    xfer += oprot->writeStructEnd();
    oprot->decrementRecursionDepth();
    return xfer;
}

void swap(TaskNode &a, TaskNode &b) {
    using ::std::swap;
    swap(a.status, b.status);
    swap(a.stage_id, b.stage_id);
    swap(a.task_id, b.task_id);
    swap(a.function_name, b.function_name);
    swap(a.src_table_name, b.src_table_name);
    swap(a.src_shard_id, b.src_shard_id);
    swap(a.src_cf_name, b.src_cf_name);
    swap(a.dst_table_name, b.dst_table_name);
    swap(a.dst_cf_name, b.dst_cf_name);
    swap(a.dst_shard_id, b.dst_shard_id);
    swap(a.__isset, b.__isset);
}

TaskNode::TaskNode(const TaskNode& other47) {
    status = other47.status;
    stage_id = other47.stage_id;
    task_id = other47.task_id;
    function_name = other47.function_name;
    src_table_name = other47.src_table_name;
    src_shard_id = other47.src_shard_id;
    src_cf_name = other47.src_cf_name;
    dst_table_name = other47.dst_table_name;
    dst_cf_name = other47.dst_cf_name;
    dst_shard_id = other47.dst_shard_id;
    __isset = other47.__isset;
}
TaskNode& TaskNode::operator=(const TaskNode& other48) {
    status = other48.status;
    stage_id = other48.stage_id;
    task_id = other48.task_id;
    function_name = other48.function_name;
    src_table_name = other48.src_table_name;
    src_shard_id = other48.src_shard_id;
    src_cf_name = other48.src_cf_name;
    dst_table_name = other48.dst_table_name;
    dst_cf_name = other48.dst_cf_name;
    dst_shard_id = other48.dst_shard_id;
    __isset = other48.__isset;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const TaskNode& obj) {
    using apache::thrift::to_string;
    out << "TaskNode(";
    out << "status=" << to_string(obj.status);
    out << ", " << "stage_id=";
    (obj.__isset.stage_id ? (out << to_string(obj.stage_id)) : (out << "<null>"));
    out << ", " << "task_id=";
    (obj.__isset.task_id ? (out << to_string(obj.task_id)) : (out << "<null>"));
    out << ", " << "function_name=";
    (obj.__isset.function_name ? (out << to_string(obj.function_name)) : (out << "<null>"));
    out << ", " << "src_table_name=";
    (obj.__isset.src_table_name ? (out << to_string(obj.src_table_name)) : (out << "<null>"));
    out << ", " << "src_shard_id=";
    (obj.__isset.src_shard_id ? (out << to_string(obj.src_shard_id)) : (out << "<null>"));
    out << ", " << "src_cf_name=";
    (obj.__isset.src_cf_name ? (out << to_string(obj.src_cf_name)) : (out << "<null>"));
    out << ", " << "dst_table_name=";
    (obj.__isset.dst_table_name ? (out << to_string(obj.dst_table_name)) : (out << "<null>"));
    out << ", " << "dst_cf_name=";
    (obj.__isset.dst_cf_name ? (out << to_string(obj.dst_cf_name)) : (out << "<null>"));
    out << ", " << "dst_shard_id=";
    (obj.__isset.dst_shard_id ? (out << to_string(obj.dst_shard_id)) : (out << "<null>"));
    out << ")";
    return out;
}

}
} // namespace
