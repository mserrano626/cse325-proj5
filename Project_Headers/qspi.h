/*
 * qspi.h
 *
 *  Created on: Apr 4, 2013
 *      Author: maserra3
 */

#ifndef QSPI_H_
#define QSPI_H_

#include "support_common.h"

extern void qspi_init(int bits, int fqspi, int delay);
extern void qspi_transmit(int n, int *data);

#endif /* QSPI_H_ */
