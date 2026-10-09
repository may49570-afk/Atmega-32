/**
 * @file SPI_config.h
 * @brief Configuration file for the Serial Peripheral Interface (SPI) driver.
 *
 * This file defines the SPI operating mode, clock frequency,
 * interrupt configuration, and data transmission order.
 *
 * @date Sep 7, 2026
 * @author Mai Essam
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/**
 * @brief Selects the SPI operating role.
 * @details Configures the SPI as a Master.
 */
#define SPI_MS_MODE 				SPI_Master

/**
 * @brief Selects the SPI clock polarity and phase mode.
 * @details Configures the SPI to operate in Mode 0.
 */
#define SPI_MODE 					SPI_MODE0

/**
 * @brief Selects the SPI clock frequency.
 */
#define SPI_CLK 					SPI_clk_F_8

/**
 * @brief Enables or disables SPI interrupts.
 */
#define SPI_INTERRUPT_MODE			SPI_INTERRUPT_ENABLE

/**
 * @brief Selects the order in which data bits are transmitted.
 * @details Configures transmission with the least significant bit first.
 */
#define SPI_DATA_ORDER 				LSB

#endif /* SPI_CONFIG_H_ */
