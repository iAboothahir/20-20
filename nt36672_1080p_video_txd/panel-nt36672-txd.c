// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2021 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/module.h>
#include <linux/of.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>

struct nt36672_txd {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
	bool prepared;
};

static inline struct nt36672_txd *to_nt36672_txd(struct drm_panel *panel)
{
	return container_of(panel, struct nt36672_txd, panel);
}

#define dsi_dcs_write_seq(dsi, seq...) do {				\
		static const u8 d[] = { seq };				\
		int ret;						\
		ret = mipi_dsi_dcs_write_buffer(dsi, d, ARRAY_SIZE(d));	\
		if (ret < 0)						\
			return ret;					\
	} while (0)

static void nt36672_txd_reset(struct nt36672_txd *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	msleep(20);
}

static int nt36672_txd_on(struct nt36672_txd *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	dsi_dcs_write_seq(dsi, 0xff, 0x20);
	dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	dsi_dcs_write_seq(dsi, 0x06, 0x9e);
	dsi_dcs_write_seq(dsi, 0x07, 0x94);
	dsi_dcs_write_seq(dsi, 0x0e, 0x35);
	dsi_dcs_write_seq(dsi, 0x0f, 0x24);
	dsi_dcs_write_seq(dsi, 0x6d, 0x66);
	dsi_dcs_write_seq(dsi, 0x69, 0x99);
	dsi_dcs_write_seq(dsi, 0x95, 0xf5);
	dsi_dcs_write_seq(dsi, 0x96, 0xf5);
	dsi_dcs_write_seq(dsi, 0xff, 0x23);
	dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	dsi_dcs_write_seq(dsi, 0x12, 0x6c);
	dsi_dcs_write_seq(dsi, 0x15, 0xe6);
	dsi_dcs_write_seq(dsi, 0x16, 0x0c);
	dsi_dcs_write_seq(dsi, 0xff, 0x24);
	dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	dsi_dcs_write_seq(dsi, 0x00, 0x20);
	dsi_dcs_write_seq(dsi, 0x01, 0x20);
	dsi_dcs_write_seq(dsi, 0x02, 0x20);
	dsi_dcs_write_seq(dsi, 0x03, 0x01);
	dsi_dcs_write_seq(dsi, 0x04, 0x0b);
	dsi_dcs_write_seq(dsi, 0x05, 0x0c);
	dsi_dcs_write_seq(dsi, 0x06, 0xa9);
	dsi_dcs_write_seq(dsi, 0x07, 0x06);
	dsi_dcs_write_seq(dsi, 0x08, 0x04);
	dsi_dcs_write_seq(dsi, 0x09, 0x20);
	dsi_dcs_write_seq(dsi, 0x0a, 0x0f);
	dsi_dcs_write_seq(dsi, 0x0b, 0x20);
	dsi_dcs_write_seq(dsi, 0x0c, 0x20);
	dsi_dcs_write_seq(dsi, 0x0d, 0x20);
	dsi_dcs_write_seq(dsi, 0x0e, 0x20);
	dsi_dcs_write_seq(dsi, 0x0f, 0x17);
	dsi_dcs_write_seq(dsi, 0x10, 0x15);
	dsi_dcs_write_seq(dsi, 0x11, 0x13);
	dsi_dcs_write_seq(dsi, 0x12, 0x00);
	dsi_dcs_write_seq(dsi, 0x13, 0x00);
	dsi_dcs_write_seq(dsi, 0x14, 0x20);
	dsi_dcs_write_seq(dsi, 0x15, 0x01);
	dsi_dcs_write_seq(dsi, 0x16, 0x0b);
	dsi_dcs_write_seq(dsi, 0x17, 0x0c);
	dsi_dcs_write_seq(dsi, 0x18, 0xa9);
	dsi_dcs_write_seq(dsi, 0x19, 0x05);
	dsi_dcs_write_seq(dsi, 0x1a, 0x03);
	dsi_dcs_write_seq(dsi, 0x1b, 0x20);
	dsi_dcs_write_seq(dsi, 0x1c, 0x0f);
	dsi_dcs_write_seq(dsi, 0x1d, 0x20);
	dsi_dcs_write_seq(dsi, 0x1e, 0x20);
	dsi_dcs_write_seq(dsi, 0x1f, 0x20);
	dsi_dcs_write_seq(dsi, 0x20, 0x20);
	dsi_dcs_write_seq(dsi, 0x21, 0x17);
	dsi_dcs_write_seq(dsi, 0x22, 0x15);
	dsi_dcs_write_seq(dsi, 0x23, 0x13);
	dsi_dcs_write_seq(dsi, 0x2f, 0x04);
	dsi_dcs_write_seq(dsi, MIPI_DCS_SET_PARTIAL_ROWS, 0x08);
	dsi_dcs_write_seq(dsi, MIPI_DCS_SET_PARTIAL_COLUMNS, 0x04);
	dsi_dcs_write_seq(dsi, 0x32, 0x08);
	dsi_dcs_write_seq(dsi, 0x33, 0x02);
	dsi_dcs_write_seq(dsi, 0x34, 0x02);

	ret = mipi_dsi_dcs_set_tear_on(dsi, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	if (ret < 0) {
		dev_err(dev, "Failed to set tear on: %d\n", ret);
		return ret;
	}

	dsi_dcs_write_seq(dsi, 0x37, 0x02);
	dsi_dcs_write_seq(dsi, 0x38, 0x72);
	dsi_dcs_write_seq(dsi, 0x39, 0x72);
	dsi_dcs_write_seq(dsi, 0x3b, 0x40);
	dsi_dcs_write_seq(dsi, 0x3f, 0x72);
	dsi_dcs_write_seq(dsi, 0x60, 0x10);
	dsi_dcs_write_seq(dsi, 0x61, 0x00);
	dsi_dcs_write_seq(dsi, 0x68, 0x83);
	dsi_dcs_write_seq(dsi, 0x78, 0x00);
	dsi_dcs_write_seq(dsi, 0x79, 0x00);
	dsi_dcs_write_seq(dsi, 0x7a, 0x08);
	dsi_dcs_write_seq(dsi, 0x7b, 0x9c);
	dsi_dcs_write_seq(dsi, 0x7d, 0x06);
	dsi_dcs_write_seq(dsi, 0x7e, 0x02);
	dsi_dcs_write_seq(dsi, 0x80, 0x45);
	dsi_dcs_write_seq(dsi, 0x81, 0x06);
	dsi_dcs_write_seq(dsi, 0x8e, 0xf0);
	dsi_dcs_write_seq(dsi, 0x90, 0x00);
	dsi_dcs_write_seq(dsi, 0x92, 0x76);
	dsi_dcs_write_seq(dsi, 0x93, 0x0a);
	dsi_dcs_write_seq(dsi, 0x94, 0x0a);
	dsi_dcs_write_seq(dsi, 0x99, 0x33);
	dsi_dcs_write_seq(dsi, 0x9b, 0xff);
	dsi_dcs_write_seq(dsi, 0xb3, 0x00);
	dsi_dcs_write_seq(dsi, 0xb4, 0x04);
	dsi_dcs_write_seq(dsi, 0xb5, 0x04);
	dsi_dcs_write_seq(dsi, 0xdc, 0x00);
	dsi_dcs_write_seq(dsi, 0xdd, 0x01);
	dsi_dcs_write_seq(dsi, 0xde, 0x00);
	dsi_dcs_write_seq(dsi, 0xdf, 0x00);
	dsi_dcs_write_seq(dsi, 0xe0, 0x75);
	dsi_dcs_write_seq(dsi, 0xe9, 0x08);
	dsi_dcs_write_seq(dsi, 0xed, 0x40);
	dsi_dcs_write_seq(dsi, 0xff, 0x20);
	dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	dsi_dcs_write_seq(dsi, 0xb0,
			  0x00, 0x00, 0x00, 0x15, 0x00, 0x37, 0x00, 0x54, 0x00,
			  0x6d, 0x00, 0x84, 0x00, 0x98, 0x00, 0xac);
	dsi_dcs_write_seq(dsi, 0xb1,
			  0x00, 0xbd, 0x00, 0xf9, 0x01, 0x25, 0x01, 0x6b, 0x01,
			  0x9c, 0x01, 0xec, 0x02, 0x22, 0x02, 0x25);
	dsi_dcs_write_seq(dsi, 0xb2,
			  0x02, 0x5e, 0x02, 0x9e, 0x02, 0xc9, 0x02, 0xfd, 0x03,
			  0x21, 0x03, 0x4d, 0x03, 0x5a, 0x03, 0x68);
	dsi_dcs_write_seq(dsi, 0xb3,
			  0x03, 0x78, 0x03, 0x8b, 0x03, 0xa1, 0x03, 0xbd, 0x03,
			  0xd6, 0x03, 0xda);
	dsi_dcs_write_seq(dsi, 0xb4,
			  0x00, 0x00, 0x00, 0x15, 0x00, 0x37, 0x00, 0x54, 0x00,
			  0x6d, 0x00, 0x84, 0x00, 0x98, 0x00, 0xac);
	dsi_dcs_write_seq(dsi, 0xb5,
			  0x00, 0xbd, 0x00, 0xf9, 0x01, 0x25, 0x01, 0x6b, 0x01,
			  0x9c, 0x01, 0xec, 0x02, 0x22, 0x02, 0x25);
	dsi_dcs_write_seq(dsi, 0xb6,
			  0x02, 0x5e, 0x02, 0x9e, 0x02, 0xc9, 0x02, 0xfd, 0x03,
			  0x21, 0x03, 0x4d, 0x03, 0x5a, 0x03, 0x68);
	dsi_dcs_write_seq(dsi, 0xb7,
			  0x03, 0x78, 0x03, 0x8b, 0x03, 0xa1, 0x03, 0xbd, 0x03,
			  0xd6, 0x03, 0xda);
	dsi_dcs_write_seq(dsi, 0xb8,
			  0x00, 0x00, 0x00, 0x15, 0x00, 0x37, 0x00, 0x54, 0x00,
			  0x6d, 0x00, 0x84, 0x00, 0x98, 0x00, 0xac);
	dsi_dcs_write_seq(dsi, 0xb9,
			  0x00, 0xbd, 0x00, 0xf9, 0x01, 0x25, 0x01, 0x6b, 0x01,
			  0x9c, 0x01, 0xec, 0x02, 0x22, 0x02, 0x25);
	dsi_dcs_write_seq(dsi, 0xba,
			  0x02, 0x5e, 0x02, 0x9e, 0x02, 0xc9, 0x02, 0xfd, 0x03,
			  0x21, 0x03, 0x4d, 0x03, 0x5a, 0x03, 0x68);
	dsi_dcs_write_seq(dsi, 0xbb,
			  0x03, 0x78, 0x03, 0x8b, 0x03, 0xa1, 0x03, 0xbd, 0x03,
			  0xd6, 0x03, 0xda);
	dsi_dcs_write_seq(dsi, 0xff, 0x21);
	dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	dsi_dcs_write_seq(dsi, 0xb0,
			  0x00, 0x00, 0x00, 0x15, 0x00, 0x37, 0x00, 0x54, 0x00,
			  0x6d, 0x00, 0x84, 0x00, 0x98, 0x00, 0xac);
	dsi_dcs_write_seq(dsi, 0xb1,
			  0x00, 0xbd, 0x00, 0xf9, 0x01, 0x25, 0x01, 0x6b, 0x01,
			  0x9c, 0x01, 0xec, 0x02, 0x22, 0x02, 0x25);
	dsi_dcs_write_seq(dsi, 0xb2,
			  0x02, 0x5e, 0x02, 0x9e, 0x02, 0xc9, 0x02, 0xfd, 0x03,
			  0x21, 0x03, 0x4d, 0x03, 0x5a, 0x03, 0x68);
	dsi_dcs_write_seq(dsi, 0xb3,
			  0x03, 0x78, 0x03, 0x8b, 0x03, 0xa1, 0x03, 0xbd, 0x03,
			  0xd6, 0x03, 0xda);
	dsi_dcs_write_seq(dsi, 0xb4,
			  0x00, 0x00, 0x00, 0x15, 0x00, 0x37, 0x00, 0x54, 0x00,
			  0x6d, 0x00, 0x84, 0x00, 0x98, 0x00, 0xac);
	dsi_dcs_write_seq(dsi, 0xb5,
			  0x00, 0xbd, 0x00, 0xf9, 0x01, 0x25, 0x01, 0x6b, 0x01,
			  0x9c, 0x01, 0xec, 0x02, 0x22, 0x02, 0x25);
	dsi_dcs_write_seq(dsi, 0xb6,
			  0x02, 0x5e, 0x02, 0x9e, 0x02, 0xc9, 0x02, 0xfd, 0x03,
			  0x21, 0x03, 0x4d, 0x03, 0x5a, 0x03, 0x68);
	dsi_dcs_write_seq(dsi, 0xb7,
			  0x03, 0x78, 0x03, 0x8b, 0x03, 0xa1, 0x03, 0xbd, 0x03,
			  0xd6, 0x03, 0xda);
	dsi_dcs_write_seq(dsi, 0xb8,
			  0x00, 0x00, 0x00, 0x15, 0x00, 0x37, 0x00, 0x54, 0x00,
			  0x6d, 0x00, 0x84, 0x00, 0x98, 0x00, 0xac);
	dsi_dcs_write_seq(dsi, 0xb9,
			  0x00, 0xbd, 0x00, 0xf9, 0x01, 0x25, 0x01, 0x6b, 0x01,
			  0x9c, 0x01, 0xec, 0x02, 0x22, 0x02, 0x25);
	dsi_dcs_write_seq(dsi, 0xba,
			  0x02, 0x5e, 0x02, 0x9e, 0x02, 0xc9, 0x02, 0xfd, 0x03,
			  0x21, 0x03, 0x4d, 0x03, 0x5a, 0x03, 0x68);
	dsi_dcs_write_seq(dsi, 0xbb,
			  0x03, 0x78, 0x03, 0x8b, 0x03, 0xa1, 0x03, 0xbd, 0x03,
			  0xd6, 0x03, 0xda);
	dsi_dcs_write_seq(dsi, 0xff, 0x25);
	dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	dsi_dcs_write_seq(dsi, 0x05, 0x0c);
	dsi_dcs_write_seq(dsi, 0x0a, 0x81);
	dsi_dcs_write_seq(dsi, 0x0b, 0xd7);
	dsi_dcs_write_seq(dsi, 0x0c, 0x01);
	dsi_dcs_write_seq(dsi, 0x17, 0x82);
	dsi_dcs_write_seq(dsi, 0x21, 0x1c);
	dsi_dcs_write_seq(dsi, 0x22, 0x1c);
	dsi_dcs_write_seq(dsi, 0x24, 0x76);
	dsi_dcs_write_seq(dsi, 0x25, 0x76);
	dsi_dcs_write_seq(dsi, 0x5c, 0x25);
	dsi_dcs_write_seq(dsi, 0x5d, 0x80);
	dsi_dcs_write_seq(dsi, MIPI_DCS_SET_CABC_MIN_BRIGHTNESS, 0x80);
	dsi_dcs_write_seq(dsi, 0x5f, 0x22);
	dsi_dcs_write_seq(dsi, 0x65, 0x00);
	dsi_dcs_write_seq(dsi, 0x69, 0x60);
	dsi_dcs_write_seq(dsi, 0x6b, 0x00);
	dsi_dcs_write_seq(dsi, 0x71, 0x2d);
	dsi_dcs_write_seq(dsi, 0x80, 0x00);
	dsi_dcs_write_seq(dsi, 0x8d, 0x04);
	dsi_dcs_write_seq(dsi, 0xd7, 0x00);
	dsi_dcs_write_seq(dsi, 0xd8, 0x00);
	dsi_dcs_write_seq(dsi, 0xd9, 0x00);
	dsi_dcs_write_seq(dsi, 0xda, 0x00);
	dsi_dcs_write_seq(dsi, 0xdb, 0x00);
	dsi_dcs_write_seq(dsi, 0xdc, 0x00);
	dsi_dcs_write_seq(dsi, 0xff, 0x26);
	dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	dsi_dcs_write_seq(dsi, 0x06, 0xc8);
	dsi_dcs_write_seq(dsi, 0x12, 0x5a);
	dsi_dcs_write_seq(dsi, 0x19, 0x0a);
	dsi_dcs_write_seq(dsi, 0x1a, 0x97);
	dsi_dcs_write_seq(dsi, 0x1d, 0x0a);
	dsi_dcs_write_seq(dsi, 0x1e, 0x1e);
	dsi_dcs_write_seq(dsi, 0x99, 0x20);
	dsi_dcs_write_seq(dsi, 0xff, 0x27);
	dsi_dcs_write_seq(dsi, 0xfb, 0x01);
	dsi_dcs_write_seq(dsi, 0x13, 0x0e);
	dsi_dcs_write_seq(dsi, 0x16, 0xb0);
	dsi_dcs_write_seq(dsi, 0x17, 0xd0);
	dsi_dcs_write_seq(dsi, 0xff, 0x10);
	dsi_dcs_write_seq(dsi, 0xfb, 0x01);

	ret = mipi_dsi_dcs_exit_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to exit sleep mode: %d\n", ret);
		return ret;
	}
	msleep(70);

	ret = mipi_dsi_dcs_set_display_on(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to set display on: %d\n", ret);
		return ret;
	}
	usleep_range(10000, 11000);

	return 0;
}

static int nt36672_txd_off(struct nt36672_txd *ctx)
{
	struct mipi_dsi_device *dsi = ctx->dsi;
	struct device *dev = &dsi->dev;
	int ret;

	ret = mipi_dsi_dcs_set_display_off(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to set display off: %d\n", ret);
		return ret;
	}
	msleep(50);

	ret = mipi_dsi_dcs_enter_sleep_mode(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to enter sleep mode: %d\n", ret);
		return ret;
	}
	msleep(120);

	return 0;
}

static int nt36672_txd_prepare(struct drm_panel *panel)
{
	struct nt36672_txd *ctx = to_nt36672_txd(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	if (ctx->prepared)
		return 0;

	nt36672_txd_reset(ctx);

	ret = nt36672_txd_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	ctx->prepared = true;
	return 0;
}

static int nt36672_txd_unprepare(struct drm_panel *panel)
{
	struct nt36672_txd *ctx = to_nt36672_txd(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	if (!ctx->prepared)
		return 0;

	ret = nt36672_txd_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	ctx->prepared = false;
	return 0;
}

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

static int nt36672_txd_get_modes(struct drm_panel *panel,
				 struct drm_connector *connector)
{
	struct drm_display_mode *mode;

	mode = drm_mode_duplicate(connector->dev, &nt36672_txd_mode);
	if (!mode)
		return -ENOMEM;

	drm_mode_set_name(mode);

	mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
	connector->display_info.width_mm = mode->width_mm;
	connector->display_info.height_mm = mode->height_mm;
	drm_mode_probed_add(connector, mode);

	return 1;
}

static const struct drm_panel_funcs nt36672_txd_panel_funcs = {
	.prepare = nt36672_txd_prepare,
	.unprepare = nt36672_txd_unprepare,
	.get_modes = nt36672_txd_get_modes,
};

static int nt36672_txd_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct nt36672_txd *ctx;
	int ret;

	ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return -ENOMEM;

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_VIDEO_BURST |
			  MIPI_DSI_MODE_VIDEO_HSE | MIPI_DSI_MODE_EOT_PACKET |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM;

	drm_panel_init(&ctx->panel, dev, &nt36672_txd_panel_funcs,
		       DRM_MODE_CONNECTOR_DSI);

	ret = drm_panel_of_backlight(&ctx->panel);
	if (ret)
		return dev_err_probe(dev, ret, "Failed to get backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		dev_err(dev, "Failed to attach to DSI host: %d\n", ret);
		drm_panel_remove(&ctx->panel);
		return ret;
	}

	return 0;
}

static int nt36672_txd_remove(struct mipi_dsi_device *dsi)
{
	struct nt36672_txd *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);

	return 0;
}

static const struct of_device_id nt36672_txd_of_match[] = {
	{ .compatible = "mdss,nt36672-txd" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, nt36672_txd_of_match);

static struct mipi_dsi_driver nt36672_txd_driver = {
	.probe = nt36672_txd_probe,
	.remove = nt36672_txd_remove,
	.driver = {
		.name = "panel-nt36672-txd",
		.of_match_table = nt36672_txd_of_match,
	},
};
module_mipi_dsi_driver(nt36672_txd_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for nt36672 1080p video mode dsi txd panel");
MODULE_LICENSE("GPL v2");
