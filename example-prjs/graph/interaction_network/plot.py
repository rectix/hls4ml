import matplotlib.pyplot as plt
import mplhep as hep
import numpy as np

plt.style.use(hep.style.CMS)

BP = [8, 10, 12, 14, 16, 18, 20]
AUC = [0.7065217391304348, 0.8387185998999862, 0.8093802728088502, 0.8073626745476572, 0.7881160921650896, 0.7894895487948113, 0.7902295465543188]

plt.figure(figsize=(6,6))
plt.plot(BP, 100*np.array(AUC), '-o', lw=2)
plt.xlabel('Bit precision')
plt.ylabel('AUC [%]')
#plt.title('Latency vs Reuse factor')
plt.tight_layout()
plt.savefig('AUC_vs_BP.pdf')
