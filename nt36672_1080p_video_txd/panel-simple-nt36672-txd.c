// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2013, The Linux Foundation. All rights reserved.

static const struct drm_display_mode nt36672_txd_mode = {
	.clock = (1080 + 122 + 8 + 76) * (2160 + 20 + 4 + 28) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 122,
	.hsync_end = 1080 + 122 + 8,
	.htotal = 1080 + 122 + 8 + 76,
	.vdisplay = 2160,
	.vsync_start = 2160 + 20,
	.vsync_end = 2160 + 20 + 4,
	.vtotal = 2160 + 20 + 4 + 28,
	.width_mm = 68,
	.height_mm = 136,
};

static const struct panel_desc_dsi nt36672_txd = {
	.desc = {
		.modes = &nt36672_txd_mode,
		.num_modes = 1,
		.bpc = 8,
		.size = {
			.width = 68,
			.height = 136,
		},
		.connector_type = DRM_MODE_CONNECTOR_DSI,
	},
	.flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
		 MIPI_DSI_MODE_VIDEO_HSE | MIPI_DSI_MODE_EOT_PACKET |
		 MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM,
	.format = MIPI_DSI_FMT_RGB888,
	.lanes = 4,
};
