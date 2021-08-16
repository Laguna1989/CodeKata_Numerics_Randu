from randu import Randu


def test_randu_initial_value():
    r = Randu()
    assert r.get() == 1


def test_randu_consecutive_values():
    r = Randu()
    values = []
    for i in range(0, 11):
        values.append(r.get())
        r.next()

    expected_values = [1, 65539, 393225, 1769499, 7077969, 26542323, 95552217, 334432395, 1146624417, 1722371299,
                       14608041]

    assert values == expected_values
