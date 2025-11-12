import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('sales_data.csv', encoding ="unicode_escape")
df

df = df.dropna(subset=['SALES', 'QUANTITYORDERED', 'PRICEEACH'])

X = df[['SALES', 'QUANTITYORDERED', 'PRICEEACH']]

from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

from sklearn.cluster import KMeans
inertia = []
K = range(1, 11)    
for k in K:
    model = KMeans(n_clusters=k, random_state=42)
    model.fit(X_scaled)
    inertia.append(model.inertia_)

plt.plot(K, inertia)
plt.xlabel('Number of clusters (k)')
plt.ylabel('Inertia')
plt.show()

optimal_k = 4
model = KMeans(n_clusters=optimal_k, random_state=42)
df['Cluster'] = model.fit_predict(X_scaled)
df[['SALES', 'QUANTITYORDERED', 'PRICEEACH', 'Cluster']]