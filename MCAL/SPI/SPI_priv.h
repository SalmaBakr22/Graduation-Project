#ifndef SPI_PRIV_H
#define SPI_PRIV_H


#define SPI_LSB_FIRST    1
#define SPI_MSB_FIRST    0

#define SPI_CLK_LOW      0
#define SPI_CLK_HIGH     1

#define SPI_SETUP_LEAD   1
#define SPI_SETUP_TRIL   0



#define SPI_DIV_2     4
#define SPI_DIV_4     0
#define SPI_DIV_8     5
#define SPI_DIV_16    1
#define SPI_DIV_32    6
#define SPI_DIV_64    2
#define SPI_DIV_128   3

#define SPDR   *((volatile uint8 *) 0x2F)
#define SPCR   *((volatile uint8 *) 0x2D)
#define SPSR   *((volatile uint8 *) 0x2E)

#endif
