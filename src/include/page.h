#ifndef PAGE_H
#define PAGE_H

#include <stdlib.h>
#include <stdint.h>

#define PAGE_SIZE 8192
#define PAGE_HEADER_SIZE 24

typedef struct {
	unsigned	lp_off:15,		/* offset to tuple (from start of page) */
				lp_flags:2,		/* state of line pointer - will maybe implement this in the future */
				lp_len:15;		/* byte length of tuple */
} ItemIdData;

typedef struct {
  void* pd_lsn;
  uint16_t pd_checksum;
  uint16_t pd_flags;
  uint16_t pd_lower;
  uint16_t pd_upper;
  uint16_t pd_special;
  uint16_t pd_pagesize_version;
  uint32_t pd_prune_xid;
} PageHeader;

typedef struct {
  PageHeader page_header;
  ItemIdData line_ptr[];
  
} Page;

#endif /* PAGE_H */