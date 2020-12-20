# Geni notes

## Downstream -> Upstream Changes

gi2c->xfer                                    -> gi2c->done
gi2c->base                                    -> gi2c->se.base
gi2c->xfer_timeout                            -> wait_for_completion_timeout(&gi2c->done, XFER_TIMEOUT);
gi2c->wrapper_dev                             -> gi2c->se.wrapper
gi2c->i2c_rsc                                 -> gi2c->se
GENI_SE_ERR(gi2c->ipcl, true, gi2c->dev,      -> dev_err(gi2c->se.dev,
gi2c->rx_ph                                   -> geni_se_rx_dma_prep(se, dma_buf, len, &rx_dma) // Where rx_dma is your target and of type dma_addr_th
geni_se_dev->cb_dev                           -> se->wrapper->dev

# Do I need to turn clocks on/off?

in geni_i2c_runtime_resume
    se_geni_clks_on

and off in suspend

# Possible similarities

geni_se_iommu_map_buf -> geni_se_tx_dma_prep

Modify tx_dma_prep to only do register stuff in FIFO/DMA mode but not in GPI mode and use those functions instead