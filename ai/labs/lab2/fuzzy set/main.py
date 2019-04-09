import plotly.plotly as py
import plotly.graph_objs as go

def main():
    trace = go.Table(
        header=dict(values=['A Scores', 'B Scores']),
        cells=dict(values=[[100, 90, 80, 90],
                           [95, 85, 75, 95]]))

    data = [trace]
    py.iplot(data, filename='basic_table')


main()
