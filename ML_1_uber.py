import pandas as pd
import numpy as np
import seaborn as sns

df = pd.read_csv("1-uber.csv")
df.head()

df.dtypes

df.describe()

df.isna().sum()
df.dropna(inplace=True)

df.drop(['Unnamed: 0', 'key'], axis=1, inplace=True)

df["pickup_datetime"] = pd.to_datetime(df["pickup_datetime"]).dt.strftime("%H").astype('float32')
df = df.rename(columns={"pickup_datetime": "time"})

import math
def euclidean_distance(lat1, lon1, lat2, lon2):
    dlat = lat2 - lat1
    dlon = lon2 - lon1
    distance = math.sqrt(dlat**2 + dlon**2)
    return distance
df['distance'] = df.apply(
    lambda row: euclidean_distance(
        row['pickup_latitude'], 
        row['pickup_longitude'], 
        row['dropoff_latitude'], 
        row['dropoff_longitude']
    ), axis=1
)

sns.scatterplot(df, y="fare_amount", x="passenger_count")
df = df[df["passenger_count"] < 15]

def remove_outliers(feature):
    global df
    q3 , q1 = np.percentile( df[feature] , [ 75 , 25 ] )
    iqr = q3 - q1
    df = df[ (df[feature] >= q1 - 1.5 * iqr) & (df[feature] <= q3 + 1.5 * iqr) ]
remove_outliers("pickup_latitude")
remove_outliers("pickup_longitude")
remove_outliers("dropoff_latitude")
remove_outliers("dropoff_longitude")

df.corr(method="pearson")

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
X = df.drop('fare_amount', axis=1)
y = df['fare_amount']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

from sklearn.linear_model import LinearRegression
model = LinearRegression()
model.fit(X_train_scaled, y_train)
y_pred = model.predict(X_test_scaled)

from sklearn.metrics import r2_score
from sklearn.metrics import root_mean_squared_error
print("R2 score: ", r2_score(y_test, y_pred))
print("RMSE: ", root_mean_squared_error(y_test, y_pred))

from sklearn.ensemble import RandomForestRegressor
model = RandomForestRegressor()
model.fit(X_train_scaled, y_train)
y_pred = model.predict(X_test_scaled)

from sklearn.metrics import r2_score
from sklearn.metrics import root_mean_squared_error
print("R2 score: ", r2_score(y_test, y_pred))
print("RMSE: ", root_mean_squared_error(y_test, y_pred))