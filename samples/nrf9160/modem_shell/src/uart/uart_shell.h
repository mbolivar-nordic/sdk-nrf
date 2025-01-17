/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef MOSH_UART_SHELL_H
#define MOSH_UART_SHELL_H

void uart_toggle_power_state_at_event(const struct shell *shell,
				       const struct lte_lc_evt *const evt);

/**
 * @brief Toggles UART0 and UART1 power states.
 *
 * @details Checks the current power state of UART0. If UART0 is currently in
 * PM_DEVICE_STATE_ACTIVE, both UART0 and UART1 are set to PM_DEVICE_STATE_LOW_POWER. If UART0 is
 * currently in any other state than PM_DEVICE_STATE_ACTIVE, both UARTs are set to active state.
 *
 * @param[in] shell Pointer to shell instance.
 */
void uart_toggle_power_state(const struct shell *shell);

#endif /* MOSH_UART_SHELL_H */
