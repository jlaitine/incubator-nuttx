# ##############################################################################
# drivers/1wire/CMakeLists.txt
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed to the Apache Software Foundation (ASF) under one or more contributor
# license agreements.  See the NOTICE file distributed with this work for
# additional information regarding copyright ownership.  The ASF licenses this
# file to you under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License.  You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations under
# the License.
#
# ##############################################################################

if(CONFIG_1WIRE)
  set(SRCS 1wire.c 1wire_crc.c 1wire_read.c 1wire_write.c 1wire_writeread.c)

  if(CONFIG_1WIRE_DS28E17)
    list(APPEND SRCS ds28e17.c)
  endif()

  target_sources(drivers PRIVATE ${SRCS})
endif()
