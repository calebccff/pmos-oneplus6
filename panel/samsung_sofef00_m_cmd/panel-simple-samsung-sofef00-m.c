// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2013, The Linux Foundation. All rights reserved.

static const struct drm_display_mode samsung_sofef00_m_mode = {
	.clock = (1080 + 112 + 16 + 36) * (2280 + 36 + 8 + 12) * 90 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 112,
	.hsync_end = 1080 + 112 + 16,
	.htotal = 1080 + 112 + 16 + 36,
	.vdisplay = 2280,
	.vsync_start = 2280 + 36,
	.vsync_end = 2280 + 36 + 8,
	.vtotal = 2280 + 36 + 8 + 12,
	.width_mm = 68,
	.height_mm = 145,
};

static const struct panel_desc_dsi samsung_sofef00_m = {
	.desc = {
		.modes = &samsung_sofef00_m_mode,
		.num_modes = 1,
		.bpc = 8,
		.size = {
			.width = 68,
			.height = 145,
		},
	},
	.flags = MIPI_DSI_MODE_VIDEO_BURST | MIPI_DSI_MODE_EOT_PACKET |
		 MIPI_DSI_CLOCK_NON_CONTINUOUS,
	.format = MIPI_DSI_FMT_RGB888,
	.lanes = 4,
};
