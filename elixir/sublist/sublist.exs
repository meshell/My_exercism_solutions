defmodule Sublist do
  @doc """
  Returns whether the first list is a sublist or a superlist of the second list
  and if not whether it is equal or unequal to the second list.
  """
  def compare(a,b) do
    cond do
      a === b ->          :equal
      is_sublist?(a,b) -> :sublist
      is_sublist?(b,a) -> :superlist
      true ->             :unequal
    end
  end

  defp is_sublist?(list1, list2=[_|tail2]) do
    if is_at_head?(list1, list2) do
      true
    else
      is_sublist?(list1, tail2)
    end
  end

  defp is_sublist?(a, b), do: is_at_head?(a,b)

  defp is_at_head?([],_), do: true
  defp is_at_head?(_,[]), do: false

  defp is_at_head?([a|tail1], [b|tail2]) when a === b do
    is_at_head?(tail1,tail2)
  end

  defp is_at_head?(_,_), do: false

end
