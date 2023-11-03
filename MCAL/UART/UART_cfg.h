#ifndef SPI_CFG_H
#define SPI_CFG_H

#define SPI_DATA_ORDER       SPI_LSB_FIRST

#define SPI_MODE             SPI_MASTER

#define SPI_CLK_IDLE_STATE   SPI_CLK_LOW

#define SPI_PHASE            SPI_SETUP_LEAD

#if SPI_MODE    ==   SPI_MASTER
#define SPI_PRESCALLER    SPI_DIV_8
#endif

#endif
