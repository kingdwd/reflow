#ifndef STATUS_H
#define	STATUS_H

#ifdef	__cplusplus
extern "C" {
#endif

// =============================================================================
// Include statements
// =============================================================================

#include <stdint.h>
#include <stdbool.h>

// =============================================================================
// Public type definitions
// =============================================================================

typedef enum
{
    // Error flag
    STATUS_CRITICAL_ERROR_FLAG,

    // Event flags
    STATUS_UART_RECEIVE_FLAG,
    STATUS_START_TEMP_READING_FLAG,
    STATUS_RUN_PID_FLAG,
    STATUS_LCD_REFRESH_FLAG,
    STATUS_UART_LOG_TEMP_FLAG,
    STATUS_START_BUTTON_PUSHED_FLAG,
    STATUS_STOP_BUTTON_PUSHED_FLAG,
    STATUS_SWITCH_TO_LEAD_FLAG,
    STATUS_SWITCH_TO_LEAD_FREE_FLAG,
    STATUS_REFLOW_TIME_UPDATED_FLAG,
    STATUS_REFLOW_PROGRAM_END_FLAG,

    // Status runtime values
    STATUS_REFLOW_PROGRAM_ACTIVE,
    STATUS_REFLOW_STATE,

    STATUS_BYTE_LAST
} status_byte_index_t;

typedef enum
{
    CRIT_ERR_NO_ERROR = 0,
    CRIT_ERR_LOOSE_THERMOCOUPLE,
    CRIT_ERR_INVALID_TEMP_READING,
    CRIT_ERR_OVERTEMP,
    CRIT_ERR_READ_TIMEOUT,
} critical_error_t;

typedef enum
{
    STATUS_REFLOW_STATE_PREHEAT,
    STATUS_REFLOW_STATE_SOAK,
    STATUS_REFLOW_STATE_REFLOW,
    STATUS_REFLOW_STATE_COOL
} status_reflow_state_t;

typedef uint8_t status_item_t;
    
// =============================================================================
// Global variable declarations
// =============================================================================

extern volatile status_item_t status_bytes[STATUS_BYTE_LAST];

// =============================================================================
// Global constatants
// =============================================================================

#define STATUS_PERIPHERAL_FREQ 16000000

// =============================================================================
// Public function declarations
// =============================================================================

/**
 * @brief Inititalizes the status variables.
 */
void status_init(void);

/**
 * @brief Checks the value of one status item.
 * @param index - index of the item to check.
 * @return status item to check.
 */
static inline status_item_t status_check(status_byte_index_t index)
{
    return status_bytes[index];
}

/**
 * @brief Sets the value of one status item.
 * @param index - index of the item to set the value of.
 * @param val - new value to assign the chosen status item.
 */
static inline void status_set(status_byte_index_t index, status_item_t val)
{
    status_bytes[index] = val;
}

/**
 * @brief Sets the value of one status item to 0.
 * @param index - index of the item to set the value of.
 */
static inline void status_clear(status_byte_index_t index)
{
    status_bytes[index] = 0;
}

#ifdef	__cplusplus
}
#endif

#endif	/* STATUS_H */

