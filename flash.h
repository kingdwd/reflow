/*
 * This file allows one to use the flash memory as non volatile data memory.
 *
 * The data memory is 1536 bytes long and resides in the instruction
 * memory space. In order to change one byte, the whole 1536 bytes sector has
 * to be erased and reprogramed. Therefore writes should be done together as
 * much as possible in order to minimize wear.
 *
 * Write operations are slow and will stall be whole processor.
 */


#ifndef FLASH_H
#define	FLASH_H

#ifdef	__cplusplus
extern "C" {
#endif

// =============================================================================
// Include statements
// =============================================================================

#include <stdbool.h>
#include <stdint.h>

// =============================================================================
// Public type definitions
// =============================================================================

typedef enum
{
    FLASH_INDEX_WDT_RESETS
} flash_index_t;

// =============================================================================
// Global variable declarations
// =============================================================================

// =============================================================================
// Global constatants
// =============================================================================


// Number of bytes the can be stored in the data memory.
#define FLASH_MEM_SIZE  1024

// =============================================================================
// Public function declarations
// =============================================================================

/**
 * @brief Reads one byte from the flash memory.
 * @param index     Index to read from.
 * @return the read value.
 */
uint8_t flash_read_byte(flash_index_t index);

/**
 * @brief Reads one word from the flash memory.
 * @param index     Index to read from.
 * @return the read value.
 */
uint16_t flash_read_word(flash_index_t index);

/**
 * @brief Reads one double word from the flash memory.
 * @param index     Index to read from.
 * @return the read value.
 */
uint32_t flash_read_dword(flash_index_t index);

/**
 * @brief Makes a RAM copy of the flash data memory.
 */
void flash_init_write_buffer(void);

/**
 * @brief Updates one byte in the data memory buffer.
 * @param index     Index to the byte to modify.
 * @param data      The byte to write.
 */
void flash_write_byte_to_buffer(flash_index_t index, uint8_t data);

/**
 * @brief Updates one word in the data memory buffer.
 * @param index     Index to the word to modify.
 * @param data      The word to write.
 */
void flash_write_word_to_buffer(flash_index_t index, uint16_t data);

/**
 * @brief Updates one double word in the data memory buffer.
 * @param index     Index to the dword to modify.
 * @param data      The dword to write.
 */
void flash_write_dword_to_buffer(flash_index_t index, uint32_t data);

/**
 * @brief Writes the data memory buffer to the flash memory.
 * @details This function is blocking and will stall the entire cpu
 * for up to a few milliseconds.
 */
void flash_write_buffer_to_flash(void);

#ifdef	__cplusplus
}
#endif

#endif	/* FLASH_H */

