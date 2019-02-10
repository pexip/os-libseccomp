/*
 * Copyright 2015 IBM
 * Author: Jan Willeke <willeke@linux.vnet.com.com>
 */

#ifndef _ARCH_S390_H
#define _ARCH_S390_H

#include <inttypes.h>

#include "arch.h"
#include "db.h"
#include "system.h"

#define s390_arg_count_max		6

extern const struct arch_def arch_def_s390;
#define s390_arg_offset(x)		(offsetof(struct seccomp_data, args[x]))

int s390_syscall_resolve_name(const char *name);
const char *s390_syscall_resolve_num(int num);

const struct arch_syscall_def *s390_syscall_iterate(unsigned int spot);

int s390_syscall_rewrite(int *syscall);

int s390_rule_add(struct db_filter_col *col, struct db_filter *db, bool strict,
		  struct db_api_rule_list *rule);

#endif
