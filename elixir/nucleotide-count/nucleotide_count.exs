defmodule NucleotideCount do
  @nucleotides [?A, ?C, ?G, ?T]

  @doc """
  Counts individual nucleotides in a NucleotideCount strand.

  ## Examples

  iex> NucleotideCount.count('AATAA', ?A)
  4

  iex> NucleotideCount.count('AATAA', ?T)
  1
  """
  @spec count([char], char) :: non_neg_integer
  def count(strand, nucleotide) do
    cond do
      ! Enum.member?(@nucleotides, nucleotide) -> raise ArgumentError
      ! validate_strand?(strand) -> raise ArgumentError
      true -> strand |> Enum.count(&(&1 == nucleotide))
    end
  end


  @doc """
  Returns a summary of counts by nucleotide.

  ## Examples

  iex> NucleotideCount.histogram('AATAA')
  %{?A => 4, ?T => 1, ?C => 0, ?G => 0}
  """
  @spec histogram([char]) :: map
  def histogram(strand) do
    if validate_strand?(strand) do
      Enum.reduce(@nucleotides, %{}, fn(n, acc) ->
        Map.put(acc, n, count(strand, n)) end)
    else
      raise ArgumentError
    end
  end

  def validate_strand?(strand) do
    ! Regex.match?(~r/[^ATCG]+/u, to_string(strand))
  end
end
