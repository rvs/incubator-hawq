/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/**
 * @file
 * \brief Special floating-point numbers
 */
#ifndef FLOATSPECIALS_H
#define FLOATSPECIALS_H

/* Convenience functions */
#if defined(_MSC_VER)
#define MKINT(x) (x##UL)
#define MKINT64(x) (x##Ui64)
#define BIT(x) (1Ui64 << (x))
#else
#define MKINT(x) (x##U)
#define MKINT64(x) (x##ULL)
#define BIT(x) (1ULL << (x))
#endif

/* 32-bit special value ranges */

#define NEG_QUIET_NAN_MIN32    MKINT(0xFFC00001)
#define NEG_QUIET_NAN_MAX32    MKINT(0xFFFFFFFF)

#define INDETERMINATE_MIN32    MKINT(0xFFC00000)
#define INDETERMINATE_MAX32    MKINT(0xFFC00000)

#define NEG_SIGNAL_NAN_MIN32   MKINT(0xFF800001)
#define NEG_SIGNAL_NAN_MAX32   MKINT(0xFFBFFFFF)

#define NEG_INFINITY_MIN32     MKINT(0xFF800000)

#define NEG_NORMALIZED_MIN32   MKINT(0x80800000)
#define NEG_NORMALIZED_MAX32   MKINT(0xFF7FFFFF)

#define NEG_DENORMALIZED_MIN32 MKINT(0x80000001)
#define NEG_DENORMALIZED_MAX32 MKINT(0x807FFFFF)

#define NEG_ZERO_MIN32         MKINT(0x80000000)
#define NEG_ZERO_MAX32         MKINT(0x80000000)

#define POS_ZERO_MIN32         MKINT(0x00000000)
#define POS_ZERO_MAX32         MKINT(0x00000000)

#define POS_DENORMALIZED_MIN32 MKINT(0x00000001)
#define POS_DENORMALIZED_MAX32 MKINT(0x007FFFFF)

#define POS_NORMALIZED_MIN32   MKINT(0x00800000)
#define POS_NORMALIZED_MAX32   MKINT(0x7F7FFFFF)

#define POS_INFINITY_MIN32     MKINT(0x7F800000)
#define POS_INFINITY_MAX32     MKINT(0x7F800000)

#define POS_SIGNAL_NAN_MIN32   MKINT(0x7F800001)
#define POS_SIGNAL_NAN_MAX32   MKINT(0x7FBFFFFF)

#define POS_QUIET_NAN_MIN32    MKINT(0x7FC00000)
#define POS_QUIET_NAN_MAX32    MKINT(0x7FFFFFFF)

/* 64-bit special value ranges */

#define NEG_QUIET_NAN_MIN64    MKINT64(0xFFF8000000000001)
#define NEG_QUIET_NAN_MAX64    MKINT64(0xFFFFFFFFFFFFFFFF)

#define INDETERMINATE_MIN64    MKINT64(0xFFF8000000000000)
#define INDETERMINATE_MAX64    MKINT64(0xFFF8000000000000)

#define NEG_SIGNAL_NAN_MIN64   MKINT64(0xFFF7FFFFFFFFFFFF)
#define NEG_SIGNAL_NAN_MAX64   MKINT64(0xFFF0000000000001)

#define NEG_INFINITY_MIN64     MKINT64(0xFFF0000000000000)

#define NEG_NORMALIZED_MIN64   MKINT64(0xFFEFFFFFFFFFFFFF)
#define NEG_NORMALIZED_MAX64   MKINT64(0x8010000000000000)

#define NEG_DENORMALIZED_MIN64 MKINT64(0x800FFFFFFFFFFFFF)
#define NEG_DENORMALIZED_MAX64 MKINT64(0x8000000000000001)

#define NEG_ZERO_MIN64         MKINT64(0x8000000000000000)
#define NEG_ZERO_MAX64         MKINT64(0x8000000000000000)

#define POS_ZERO_MIN64         MKINT64(0x0000000000000000)
#define POS_ZERO_MAX64         MKINT64(0x0000000000000000)

#define POS_DENORMALIZED_MIN64 MKINT64(0x0000000000000001)
#define POS_DENORMALIZED_MAX64 MKINT64(0x000FFFFFFFFFFFFF)

#define POS_NORMALIZED_MIN64   MKINT64(0x0010000000000000)
#define POS_NORMALIZED_MAX64   MKINT64(0x7FEFFFFFFFFFFFFF)

#define POS_INFINITY_MIN64     MKINT64(0x7FF0000000000000)
#define POS_INFINITY_MAX64     MKINT64(0x7FF0000000000000)

#define POS_SIGNAL_NAN_MIN64   MKINT64(0x7FF0000000000001)
#define POS_SIGNAL_NAN_MAX64   MKINT64(0x7FF7FFFFFFFFFFFF)

#define POS_QUIET_NAN_MIN64    MKINT64(0x7FF8000000000000)
#define POS_QUIET_NAN_MAX64    MKINT64(0x7FFFFFFFFFFFFFFF)

typedef enum
{
	POS_QNAN_BIT,
	NEG_QNAN_BIT,
	POS_SNAN_BIT,
	NEG_SNAN_BIT,
	POS_INF_BIT,
	NEG_INF_BIT,
	POS_DEN_BIT,
	NEG_DEN_BIT,
	POS_NOR_BIT,
	NEG_NOR_BIT,
	POS_ZERO_BIT,
	NEG_ZERO_BIT,
	INDETERM_BIT,
	BUG_BIT
} ieee_selects;

#define MSK_POS_QNAN BIT(POS_QNAN_BIT)
#define MSK_POS_SNAN BIT(POS_SNAN_BIT)
#define MSK_POS_INF  BIT(POS_INF_BIT)
#define MSK_POS_DEN  BIT(POS_DEN_BIT)
#define MSK_POS_NOR  BIT(POS_NOR_BIT)
#define MSK_POS_ZERO BIT(POS_ZERO_BIT)
#define MSK_NEG_QNAN BIT(NEG_QNAN_BIT)
#define MSK_NEG_SNAN BIT(NEG_SNAN_BIT)
#define MSK_NEG_INF  BIT(NEG_INF_BIT)
#define MSK_NEG_DEN  BIT(NEG_DEN_BIT)
#define MSK_NEG_NOR  BIT(NEG_NOR_BIT)
#define MSK_NEG_ZERO BIT(NEG_ZERO_BIT)
#define MSK_INDETERM BIT(INDETERM_BIT)
#define MSK_BUG      BIT(BUG_BIT)

// Definitions for IEEE -inf, inf, -0 compressed out of the sparse vector along with zero
#define ZERO_i     	MKINT64(0x0)
#define INF_i     	POS_INFINITY_MIN64
#define NEGINF_i  	NEG_INFINITY_MIN64
#define NVP_i		NEG_QUIET_NAN_MIN64

// Reading a member of a union different from the one written to is undefined in
// C99, yet it is very common practice.
static const union {
    uint64_t asInt64;
    double asDouble;
} COMPVEC[] = { { 5 }, { ZERO_i }, { INF_i }, { NEGINF_i }, { NVP_i } };

static inline double _LAL_for_compiler_unused_warning(void) {return(COMPVEC[0].asDouble);}

#define ZERO		COMPVEC[1].asDouble
#define INF		COMPVEC[2].asDouble
#define NEGINF		COMPVEC[3].asDouble
#define NVP		COMPVEC[4].asDouble

#endif 	/* FLOATSPECIALS_H */
