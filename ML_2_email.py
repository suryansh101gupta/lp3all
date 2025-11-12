import pandas as pd

df = pd.read_csv('2-emails.csv')
df

df.isnull().sum()

df.drop('Email No.', inplace=True, axis=1)

from sklearn.model_selection import train_test_split

X = df.drop('Prediction', axis=1)
y = df['Prediction']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

from sklearn.neighbors import KNeighborsClassifier

model = KNeighborsClassifier()
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
y_pred

from sklearn.metrics import confusion_matrix, classification_report

print("KNN Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("\n\nKNN Classification Report: \n", classification_report(y_test, y_pred))

from sklearn.svm import SVC

model = SVC(kernel='linear', probability=True)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
y_pred

print("SVM Confusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("\n\nKNN Classification Report: \n", classification_report(y_test, y_pred))