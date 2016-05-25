defmodule RunLengthEncoder do
  @doc """
  Generates a string where consecutive elements are represented as a data value and count.
  "HORSE" => "1H1O1R1S1E"
  For this example, assume all input are strings, that are all uppercase letters.
  It should also be able to reconstruct the data into its original form.
  "1H1O1R1S1E" => "HORSE"
  """
  @spec encode(String.t) :: String.t
  def encode(string) do
      cond do
      String.length(string) > 0 ->
        charlist = to_char_list(string)
        create_string = fn ({first, second}) -> Integer.to_string(length(first)) <> String.first(string) <> encode(to_string(second)) end
        create_string.(Enum.split_while(charlist, fn(c) -> c == hd(charlist) end))
      true -> string
    end
  end

  @spec decode(String.t) :: String.t
  def decode(string) do
      decode_block = fn (str) -> String.duplicate(String.last(str), String.to_integer(String.slice(str, 0..-2))) end
      Regex.scan(~r/[1-9]+[A-Z]{1}/, string)
      |>  List.flatten
      |> Enum.reduce("", fn (elem, result) -> result <> decode_block.(elem) end)
  end
end
