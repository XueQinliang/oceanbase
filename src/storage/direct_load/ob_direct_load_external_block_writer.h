// Copyright (c) 2022-present Oceanbase Inc. All Rights Reserved.
// Author:
//   suzhi.yt <>

#pragma once

#include "storage/direct_load/ob_direct_load_data_block.h"
#include "storage/direct_load/ob_direct_load_data_block_writer.h"

namespace oceanbase
{
namespace storage
{

template <typename T>
class ObDirectLoadExternalBlockWriter
  : public ObDirectLoadDataBlockWriter<ObDirectLoadDataBlock::Header, T>
{
  typedef ObDirectLoadDataBlockWriter<ObDirectLoadDataBlock::Header, T> ParentType;
public:
  ObDirectLoadExternalBlockWriter() {}
  virtual ~ObDirectLoadExternalBlockWriter() {}
  int init(int64_t data_block_size, common::ObCompressorType compressor_type, char *extra_buf,
           int64_t extra_buf_size)
  {
    return ParentType::init(data_block_size, compressor_type, extra_buf, extra_buf_size, nullptr);
  }
private:
  DISALLOW_COPY_AND_ASSIGN(ObDirectLoadExternalBlockWriter);
};

} // namespace storage
} // namespace oceanbase
