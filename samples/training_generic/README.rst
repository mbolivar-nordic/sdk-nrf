Generic NCS examples
####################

Overview
********

An example NCS application whose Git history shows generic use cases involving
drivers, hardware, and pinout management. It is based on NCS v1.2.

To get this code, go to your ``ncs/nrf`` directory and run::

  cd ncs/nrf
  git remote add -f mbolivar-nordic https://github.com/mbolivar-nordic/fw-nrfconnect-nrf
  git checkout --track mbolivar-nordic/ncs-training-2020-april
  west update

You can then look at the git history to see the changes for each demo and code
walkthrough, using a graphical tool like `TortoiseGit
<https://tortoisegit.org/>`_ or `gitk <https://git-scm.com/docs/gitk>`_, or
from the command line::

  git log --patch

Building and Running
********************

This sample can be built and flashed in Segger Embedded Studio for nRF9160 DK.

It can also be built and flashed from the command line, using west commands::

  cd ncs/nrf/samples/training_generic
  west build -b nrf9160_pca10090
  west flash

Note: the above ``nrf9160_pca10090`` board name works with NCS v1.2. The board
was renamed ``nrf9160dk_nrf9160`` in Zephyr master and a future version of NCS.

Sample Output
=============

The current version of the code just prints ``Hello Americas FAEs and sales!``
to the UART connected to the Segger interface MCU.

Subsequent commits will change that.
